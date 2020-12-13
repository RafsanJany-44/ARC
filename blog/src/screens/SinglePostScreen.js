import  React, { useEffect, useState } from "react";
import {StyleSheet, View,FlatList,Text } from "react-native";
import {AuthContext} from '../providers/AuthProvider';
import { Header,Avatar} from 'react-native-elements';
import { StatusBar } from 'expo-status-bar';
import { Ionicons } from '@expo/vector-icons';
import {Card, CardItem, Button, Left, Body, Right} from 'native-base';
import {getDataJSON} from './../functions/AsyncStorageFunctions';
import WriteComment from '../components/CommentWrite';
import ShowComment from "./../components/CommentShow";
import * as firebase from "firebase";
import "firebase/firestore";

const SinglePostScreen=({navigation,route})=>{
    if(Comment != ""){
        dict = {
            "comment_poster_id": userid,
            "commentor" : username,
            "comment_body": Comment,
        }
        const doc = firebase.firestore().collection('posts').doc(postId).update({
            comments: firebase.firestore.FieldValue.arrayUnion(dict)
        }).then(()=>{
            alert("Commented successfully");
        });
    }else{
        alert("Field is empty!");
    }
    }

    const getComments=async ()=>{
        firebase.firestore().collection('posts').doc(postId).onSnapshot((doc) => {
            let snap = doc.data();
            setPost(snap);
            setallc(snap.comments)
            
        });
    }

    useEffect(()=>{
        getPostDetails();
    },[]);

    useEffect(()=>{
        getComments();
    });

    return(
        <AuthContext.Consumer>
            {(auth)=>
            (
                <View style={styles.container}>
                    <StatusBar style="light"/>
                    <Header
                    containerStyle={{
                    backgroundColor: '#DAF7A6',
                    justifyContent: 'space-around',}}
                    leftComponent={<Ionicons name="md-arrow-back" size={25} color="black" onPress={()=>{
                        navigation.goBack();
                    }}/>}
                    centerComponent={{ text: 'Post', style: { fontSize:20,color: '#fff' } }}
                    rightComponent={<Ionicons name="md-lock" size={25} color="white" 
                    onPress={()=>{
                        auth.setisLogged(false);
                        auth.setcurrentUser({});
                    }}/>}
                    />

                <Card style={{flex: 0,marginLeft:5,marginRight:5,marginTop:10,padding:10,borderRadius:10,shadowColor:'blue', shadowOffset:10,}}>
                    <CardItem header>
                        <Left>
                            <Avatar size='medium' rounded
                                overlayContainerStyle={{backgroundColor: '#DAF7A6'}}
                                icon={{name: 'user', type: 'font-awesome'}} />
                            <Body>
                            <Text style={{fontSize:15}}>{postDetails.user_name}</Text>
                            <Text style={{color:'grey'}}>{postDetails.date}</Text>
                            </Body>
                        </Left>
                    </CardItem>
                    <CardItem>
                        <Body>
                            <Text style={{fontSize:15}}>{postDetails.post}</Text>
                        </Body>
                        
                    </CardItem>
                    <CardItem >
                        <Left style={{flex:1}}>
                            <Button transparent icon>
                                <Ionicons name="ios-heart" size={40} color="pink" />
                            </Button>
                            <Text>{postDetails.likecount}</Text>
                        </Left>
                        
                    </CardItem>
                    </Card>
                        <WriteComment user={auth.currentUser.name} postDetails={postDetails}/>
                        <FlatList
                            data={postComment}
                            // onRefresh={getComments}
                            // refreshing={reload}
                            renderItem={({item}) =>{
                                return <ShowComment content={item} />
                                // return(<Text>Hello</Text>)
                            }}
                            keyExtractor={(item, index) => index.toString()}
                        />
                </View>
                )}
        </AuthContext.Consumer>
    );


};

const styles = StyleSheet.create({
    container:{
        flex:1,
    },
});

export default SinglePostScreen;