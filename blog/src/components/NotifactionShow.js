import React from 'react';
import { Card } from 'react-native-paper';
import { FontAwesome ,AntDesign} from '@expo/vector-icons';

const ShowNotification=({content,navigation})=>{
    let comment=content.comment
    if(comment==''){
         return(<Card
          style={{borderRadius:10,shadowColor:'blue', shadowOffset:10, marginTop:10,marginLeft:5,marginRight:5}} onPress={()=>navigation.push('Post',{post:content.postid})}>
                <Card.Title title={content.sender} subtitle=" liked your post" left={()=><AntDesign name="heart" size={24} color="#FC5E5E"/>} />
            </Card>);
    }
    else{
         return(<Card
            style={{borderRadius:10,shadowColor:'blue', shadowOffset:10, marginTop:10,marginLeft:5,marginRight:5}} onPress={()=>navigation.push('Post',{post:content.postid})}>
                <Card.Title title={content.sender} subtitle=" commented on your post"  left={()=><FontAwesome name="comment" size={24} color="#3D6DCC" />} />
            </Card>);
    }
   
};


export default ShowNotification;