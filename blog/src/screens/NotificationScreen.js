import React,{useState,useEffect} from 'react';
import {  FlatList, View } from 'react-native';
import {Header} from 'react-native-elements';
import {AuthContext} from '../providers/AuthProvider';
import { Ionicons} from '@expo/vector-icons';
import { getDataJSON } from "./../functions/AsyncStorageFunctions";
import  ShowNotification  from "./../components/NotifactionShow";
import * as firebase from "firebase";


const  NotificationScreen =({navigation})=> {
    let [notification,setNotification]=useState([]);
    const [reload,setReload]=useState(false);

    const getNotification = async ()=>{
        setReload(true)
        firebase.auth().signInWithEmailAndPassword(Email, Password).then((userCreds) => {
            auth.setIsLoggedIn(true);
            auth.setCurrentUser(userCreds.posts);
        }).catch((error) => {
            alert(error);
        })
        if(notify!=null ){
            setNotification(notify);
        }
        else
            console.log("No Notification");
        setReload(false);
    }
    useEffect(()=>{
        getNotification();
    },[]);

    return(
        <AuthContext.Consumer>
            {(auth)=>
            (
                <View style={{flex:1}} >
                    <Header
                    containerStyle={{
                    backgroundColor: '#DAF7A6',
                    justifyContent: 'space-around',
                }}
                    leftComponent={<Ionicons name="md-menu" size={25} color="#6C9800" onPress={()=>{
                        navigation.openDrawer();
                    }}/>}
                    centerComponent={{ text: 'Notification', style: {fontSize:20, color: '#6C9800' } }}
                    rightComponent={<Ionicons name="md-lock" size={25} color="#6C9800" 
                    onPress={()=>{
                        auth.setisLogged(false);
                        auth.setcurrentUser({});
                    }}/>}
                    />
                    <View>
                        <FlatList
                        data={notification}
                        onRefresh={getNotification}
                        refreshing={reload}
                        renderItem={function ({ item }) {
                            if(item.receiver==auth.currentUser.email)
                                return (
                                <ShowNotification
                                    content={item}
                                    navigation={navigation}
                                />);
                        }}
                        keyExtractor={(item, index) => index.toString()}
                        />
                    </View>
                    
                    
                </View>
                
            )}
        </AuthContext.Consumer>
    );
}



export default NotificationScreen;