import React,{useState} from 'react';
import { View } from 'react-native';

import { Card, Button ,Input} from 'react-native-elements';
import { storeDataJSON} from '../functions/AsyncStorageFunctions';
import moment from 'moment';
import { Entypo} from '@expo/vector-icons';


function ShowCurrentDate() {
      var date = new moment().format('DD MMM YYYY');
      return date;
}


const PostWrite=({user})=>{
    const [post, setPost] = useState("");
    const input = React.createRef();
    return(
    <Card containerStyle={{borderRadius:10,marginLeft:5,marginRight:5, shadowOffset:10}}>
        <Input
        ref={input}
        placeholder='Write about the unknows'
        multiline={true}
        leftIcon={<Entypo name="pencil" size={24} color="black" />}
        onChangeText={(text)=>{
            setPost(text); 
        }}
        />
        <View style={{flexDirection:'row-reverse'}}>
            <Button title='Post' buttonStyle={{width:100,alignSelf:'flex-start',backgroundColor:'#DAF7A6'}} onPress={
                ()=>{
                    id=Math.floor((Math.random() * 100000) + 1);
                    if(post.length>0){
                        let newPost={
                        id:"post"+id,
                        post:post,
                        user_name:user.name,
                        user_email:user.email,
                        date: ShowCurrentDate(),
                        likecount:0,
                        }
                        storeDataJSON("post"+id,newPost);
                        alert(posts.id)
                        setPost("");
                        input.current.clear();
                    }
                    else {
                        alert("Input Field Empty");
                    }
                }
            }/>
            <Button 
            disabled={post.length==0? true:false} 
            type='clear' title='Clear' 
            titleStyle={{color:'#3a0088'}}
            buttonStyle={{width:120,alignSelf:'flex-end'}}
            onPress={()=>{
                setPost("");
                input.current.clear();
            }}/>
        </View>
        
    </Card>
    );
    
};


export default PostWrite;