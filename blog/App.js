import React from 'react';

import { StyleSheet, Text, View } from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import { createDrawerNavigator } from '@react-navigation/drawer';
import { FontAwesome,Ionicons } from '@expo/vector-icons';
import HomeScreen from './src/screens/HomeScreen';
import LoginScreen from './src/screens/LoginScreen';
import SignupScreen from './src/screens/SignUpScreen';
import SinglePostScreen from './src/screens/SinglePostScreen';
import {AuthProvider,AuthContext} from './src/providers/AuthProvider';
import NotificationScreen from './src/screens/NotificationScreen';
import { createMaterialBottomTabNavigator } from '@react-navigation/material-bottom-tabs';
import ProfileScreen from './src/screens/ProfieScreen';


const Authstack = createStackNavigator();
const Notificationstack = createStackNavigator();
const HomeTab= createMaterialBottomTabNavigator();
const Drawer=createDrawerNavigator();

const DrawerScreens=()=>{
  return(
    <Drawer.Navigator initialRouteName="Home">
        <Drawer.Screen name="Home" component={NotificationScreenStack} />
        <Drawer.Screen name="Profile" component={ProfileScreen}/>
  </Drawer.Navigator>
  ); 
}

const HomeScreenTab=()=> {
  return(
    <HomeTab.Navigator 
    initialRouteName="Home"
      activeColor="#6C9800"
      shifting={true}>
      <HomeTab.Screen name="Home" 
        component={HomeScreen}
        options={{
          tabBarLabel: 'Home',
          tabBarColor: '#DAF7A6',
          tabBarIcon: ({color}) => (
            <FontAwesome name="home" size={24} color={color} />
          ),
        }}
        />
      <HomeTab.Screen name="Notification" 
        component={NotificationScreen}
        options={{
          tabBarLabel: 'Notification',
          tabBarColor: '#DAF7A6',
          tabBarIcon: ({color}) => (
          <Ionicons name="ios-notifications" size={24} color={color} />
          ),
        }} />
    </HomeTab.Navigator>);
};


const NotificationScreenStack=()=>{
  return(<Notificationstack.Navigator >
    <Notificationstack.Screen name="Home" component={HomeScreenTab} options={{ headerShown: false }}/>
    <Notificationstack.Screen name="Post" component={SinglePostScreen} options={{ headerShown: false }}/>
  </Notificationstack.Navigator>)

};

const AuthScreenStack=()=> {
  return(<Authstack.Navigator >
    <Authstack.Screen name='Log In' component={LoginScreen} options={{ headerShown: false }}/>
    <Authstack.Screen name='Sign Up' component={SignupScreen} options={{ headerShown: false }}/>
  </Authstack.Navigator>);
};

export default function App() {
  return (
    <AuthProvider>
      <AuthContext.Consumer>
        
        {(auth)=>(
          <NavigationContainer>
            {auth.isLogged?<DrawerScreens/>:<AuthScreenStack/>}
          </NavigationContainer>)}
      </AuthContext.Consumer>
    </AuthProvider>
    
  );
}


const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
