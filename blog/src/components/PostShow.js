import React,{useState} from 'react';
import {Card,CardItem, Left, Body, Right} from 'native-base';
import {Avatar,Button} from 'react-native-elements';
import { Ionicons } from '@expo/vector-icons';
import {Text} from 'react-native';
import {mergeData} from '../functions/AsyncStorageFunctions';
import  AddNotification  from "../functions/NotificationFunction";

import * as firebase from "firebase";
import "firebase/firestore";

const ShowPost=({content,currentuser,navigation})=>{
    const [like,setLike]=useState(content.likecount);
    return(
    <Card style={{flex: 0,marginLeft:5,marginRight:5,marginTop:10,padding:10,borderRadius:10,shadowColor:'blue', shadowOffset:10,}}>
            
                            <Input
                                placeholder="What's On Your Mind?"
                                leftIcon={<Entypo name="pencil" size={24} color="black" />}
                                on onChangeText={(currentInput)=>{
                                    setInput(currentInput)
                                }}
                            />
                            <Button title="Post" type="outline" 
                            titleStyle={{color: "#1c1c1c"}}
                            onPress={function () {
                                if(input == ""){
                                    alert("Filed is Empty!");
                                }else{
                                    setLoading(true);
                                    firebase.firestore().collection('posts').add({
                                        userId: auth.CurrentUser.uid,
                                        body: input,
                                        author: auth.CurrentUser.displayName,
                                        created_at: firebase.firestore.Timestamp.now(),
                                        likes: [],
                                        comments: [],
                                    }).then(() => {
                                        setLoading(false);
                                        alert("Post was created successfully!");
                                    }).catch((error) => {
                                        setLoading(false);
                                        alert(error);
                                    });
                                }
                            }} />
                        </Card>
};


export default ShowPost;