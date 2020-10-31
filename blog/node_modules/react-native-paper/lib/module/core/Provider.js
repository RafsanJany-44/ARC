function ownKeys(object, enumerableOnly) { var keys = Object.keys(object); if (Object.getOwnPropertySymbols) { var symbols = Object.getOwnPropertySymbols(object); if (enumerableOnly) symbols = symbols.filter(function (sym) { return Object.getOwnPropertyDescriptor(object, sym).enumerable; }); keys.push.apply(keys, symbols); } return keys; }

function _objectSpread(target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i] != null ? arguments[i] : {}; if (i % 2) { ownKeys(Object(source), true).forEach(function (key) { _defineProperty(target, key, source[key]); }); } else if (Object.getOwnPropertyDescriptors) { Object.defineProperties(target, Object.getOwnPropertyDescriptors(source)); } else { ownKeys(Object(source)).forEach(function (key) { Object.defineProperty(target, key, Object.getOwnPropertyDescriptor(source, key)); }); } } return target; }

function _defineProperty(obj, key, value) { if (key in obj) { Object.defineProperty(obj, key, { value: value, enumerable: true, configurable: true, writable: true }); } else { obj[key] = value; } return obj; }

function _extends() { _extends = Object.assign || function (target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i]; for (var key in source) { if (Object.prototype.hasOwnProperty.call(source, key)) { target[key] = source[key]; } } } return target; }; return _extends.apply(this, arguments); }

import * as React from 'react';
import { AccessibilityInfo, Appearance } from 'react-native';
import { ThemeProvider } from './theming';
import { Provider as SettingsProvider } from './settings';
import MaterialCommunityIcon from '../components/MaterialCommunityIcon';
import PortalHost from '../components/Portal/PortalHost';
import DefaultTheme from '../styles/DefaultTheme';
import DarkTheme from '../styles/DarkTheme';

const Provider = (_ref) => {
  let props = _extends({}, _ref);

  const colorSchemeName = !props.theme && (Appearance === null || Appearance === void 0 ? void 0 : Appearance.getColorScheme()) || 'light';
  const [reduceMotionEnabled, setReduceMotionEnabled] = React.useState(false);
  const [colorScheme, setColorScheme] = React.useState(colorSchemeName);

  const handleAppearanceChange = preferences => {
    const {
      colorScheme
    } = preferences;
    setColorScheme(colorScheme);
  };

  React.useEffect(() => {
    if (!props.theme) {
      AccessibilityInfo.addEventListener('reduceMotionChanged', setReduceMotionEnabled);
    }

    return () => {
      if (!props.theme) {
        AccessibilityInfo.removeEventListener('reduceMotionChanged', setReduceMotionEnabled);
      }
    };
  }, [props.theme]);
  React.useEffect(() => {
    if (!props.theme) Appearance === null || Appearance === void 0 ? void 0 : Appearance.addChangeListener(handleAppearanceChange);
    return () => {
      if (!props.theme) Appearance === null || Appearance === void 0 ? void 0 : Appearance.removeChangeListener(handleAppearanceChange);
    };
  }, [props.theme]);

  const getTheme = () => {
    const {
      theme: providedTheme
    } = props;

    if (providedTheme) {
      return providedTheme;
    } else {
      const theme = colorScheme === 'dark' ? DarkTheme : DefaultTheme;
      return _objectSpread(_objectSpread({}, theme), {}, {
        animation: _objectSpread(_objectSpread({}, theme.animation), {}, {
          scale: reduceMotionEnabled ? 0 : 1
        })
      });
    }
  };

  const {
    children,
    settings
  } = props;
  return /*#__PURE__*/React.createElement(PortalHost, null, /*#__PURE__*/React.createElement(SettingsProvider, {
    value: settings || {
      icon: MaterialCommunityIcon
    }
  }, /*#__PURE__*/React.createElement(ThemeProvider, {
    theme: getTheme()
  }, children)));
};

export default Provider;
//# sourceMappingURL=Provider.js.map