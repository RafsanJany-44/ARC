import React,{useState} from 'react';
import {Card,CardItem, Left, Body, Right} from 'native-base';
import {Avatar,Button} from 'react-native-elements';
import { Ionicons } from '@expo/vector-icons';
import {Text} from 'react-native';
import {mergeData} from '../functions/AsyncStorageFunctions';
import  AddNotification  from "../functions/NotificationFunction";


const ShowPost=({content,currentuser,navigation})=>{
    const [like,setLike]=useState(content.likecount);
    return(<Card style={{flex: 0,marginLeft:5,marginRight:5,marginTop:10,padding:10,borderRadius:10,shadowColor:'blue', shadowOffset:10,}}>
            <CardItem>
              <Left>
                    <Avatar size='medium' rounded
                    overlayContainerStyle={{backgroundColor: 'grey'}}
                    icon={{name: 'user', type: 'font-awesome'}} />
                <Body>
                    <Text>{content.user_name}</Text>
                    <Text note>{content.date}</Text>
                </Body>
              </Left>
            </CardItem>
            <CardItem>
              <Body>
                <Text>
                  {content.post}
                </Text>
              </Body>
            </CardItem>
            <CardItem>
                <Left>
                    <Button 
                    type="clear" 
                    icon={<Ionicons name="md-heart-empty" size={40} color="pink" />} 
                    onPress={async ()=>{
                        await mergeData(content.id,JSON.stringify({likecount:like+1}));
                        let likedjson={
                          postid:content.id,
                          comment:"",
	                        receiver:content.user_email,
                          sender:currentuser.name,
                        };
                        let p=await AddNotification(likedjson);
                        setLike(like+1)
                    }}>
                    </Button>
                    <Text>{like}</Text>
                </Left>
                <Right>
                  <Button buttonStyle={{backgroundColor:'#DAF7A6'}} title="Comment" onPress={()=>navigation.navigate('Post',{post:content.id})}>
                  </Button>
                </Right>
            </CardItem>
          </Card>);
};


export default ShowPost;