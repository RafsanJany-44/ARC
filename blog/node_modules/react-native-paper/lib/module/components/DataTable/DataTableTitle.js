function _extends() { _extends = Object.assign || function (target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i]; for (var key in source) { if (Object.prototype.hasOwnProperty.call(source, key)) { target[key] = source[key]; } } } return target; }; return _extends.apply(this, arguments); }

function _objectWithoutProperties(source, excluded) { if (source == null) return {}; var target = _objectWithoutPropertiesLoose(source, excluded); var key, i; if (Object.getOwnPropertySymbols) { var sourceSymbolKeys = Object.getOwnPropertySymbols(source); for (i = 0; i < sourceSymbolKeys.length; i++) { key = sourceSymbolKeys[i]; if (excluded.indexOf(key) >= 0) continue; if (!Object.prototype.propertyIsEnumerable.call(source, key)) continue; target[key] = source[key]; } } return target; }

function _objectWithoutPropertiesLoose(source, excluded) { if (source == null) return {}; var target = {}; var sourceKeys = Object.keys(source); var key, i; for (i = 0; i < sourceKeys.length; i++) { key = sourceKeys[i]; if (excluded.indexOf(key) >= 0) continue; target[key] = source[key]; } return target; }

import * as React from 'react';
import { Animated, StyleSheet, TouchableWithoutFeedback, View, I18nManager } from 'react-native';
import color from 'color';
import MaterialCommunityIcon from '../MaterialCommunityIcon';
import Text from '../Typography/Text';
import { withTheme } from '../../core/theming';

/**
 * A component to display title in table header.
 *
 * <div class="screenshots">
 *   <figure>
 *     <img class="medium" src="screenshots/data-table-header.png" />
 *   </figure>
 * </div>
 *
 *
 * ## Usage
 * ```js
 * import * as React from 'react';
 * import { DataTable } from 'react-native-paper';
 *
 * const MyComponent = () => (
 *       <DataTable>
 *         <DataTable.Header>
 *           <DataTable.Title
 *             sortDirection='descending'
 *           >
 *             Dessert
 *           </DataTable.Title>
 *           <DataTable.Title numeric>Calories</DataTable.Title>
 *           <DataTable.Title numeric>Fat (g)</DataTable.Title>
 *         </DataTable.Header>
 *       </DataTable>
 * );
 *
 * export default MyComponent;
 * ```
 */
const DataTableTitle = (_ref) => {
  let {
    numeric,
    children,
    onPress,
    sortDirection,
    theme,
    style,
    numberOfLines = 1
  } = _ref,
      rest = _objectWithoutProperties(_ref, ["numeric", "children", "onPress", "sortDirection", "theme", "style", "numberOfLines"]);

  const {
    current: spinAnim
  } = React.useRef(new Animated.Value(sortDirection === 'ascending' ? 0 : 1));
  React.useEffect(() => {
    Animated.timing(spinAnim, {
      toValue: sortDirection === 'ascending' ? 0 : 1,
      duration: 150,
      useNativeDriver: true
    }).start();
  }, [sortDirection, spinAnim]);
  const textColor = color(theme.colors.text).alpha(0.6).rgb().string();
  const spin = spinAnim.interpolate({
    inputRange: [0, 1],
    outputRange: ['0deg', '180deg']
  });
  const icon = sortDirection ? /*#__PURE__*/React.createElement(Animated.View, {
    style: [styles.icon, {
      transform: [{
        rotate: spin
      }]
    }]
  }, /*#__PURE__*/React.createElement(MaterialCommunityIcon, {
    name: "arrow-down",
    size: 16,
    color: theme.colors.text,
    direction: I18nManager.isRTL ? 'rtl' : 'ltr'
  })) : null;
  return /*#__PURE__*/React.createElement(TouchableWithoutFeedback, _extends({
    disabled: !onPress,
    onPress: onPress
  }, rest), /*#__PURE__*/React.createElement(View, {
    style: [styles.container, numeric && styles.right, style]
  }, icon, /*#__PURE__*/React.createElement(Text, {
    style: [styles.cell, sortDirection ? styles.sorted : {
      color: textColor
    }],
    numberOfLines: numberOfLines
  }, children)));
};

DataTableTitle.displayName = 'DataTable.Title';
const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'row',
    alignContent: 'center',
    paddingVertical: 12
  },
  right: {
    justifyContent: 'flex-end'
  },
  cell: {
    height: 24,
    lineHeight: 24,
    fontSize: 12,
    fontWeight: '500',
    alignItems: 'center'
  },
  sorted: {
    marginLeft: 8
  },
  icon: {
    height: 24,
    justifyContent: 'center'
  }
});
export default withTheme(DataTableTitle); // @component-docs ignore-next-line

export { DataTableTitle };
//# sourceMappingURL=DataTableTitle.js.map