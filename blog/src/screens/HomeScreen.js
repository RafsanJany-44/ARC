import React,{useState,useEffect} from 'react';
import { StatusBar } from 'expo-status-bar';
import {StyleSheet ,View,FlatList ,Button} from 'react-native';
import { Header} from 'react-native-elements';
import {AuthContext} from './../providers/AuthProvider';
import { Ionicons } from '@expo/vector-icons';
import PostWrite from './../components/PostWrite';
import ShowPost from './../components/PostShow';



import { getDataJSON, getAllKeys} from '../functions/AsyncStorageFunctions';


const  HomeScreen =({navigation})=> {
    const [posts,setPosts]=useState([]);
    const [reload,setReload]=useState(false)
    const getPosts = async ()=>{
        setReload(true)
        let keys=await getAllKeys();
        let Allposts=[];
        if(keys!=null ){
            for (let key of keys) {
                if (key.startsWith('post')) {
                    let post=await getDataJSON(key);
                    Allposts.push(post);
                }
            }
            setPosts(Allposts);
        }
        else
            console.log("no keys");
        setReload(false);
    }

    useEffect(()=>{
        getPosts();
    },[]);
    

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
                    leftComponent={<Ionicons name="md-menu" size={25} color="#6C9800" onPress={()=>{
                        navigation.openDrawer();
                    }}/>}
                    centerComponent={{ text: 'Home', style: { fontSize:20,color: '#6C9800' } }}
                    rightComponent={<Ionicons name="md-lock" size={25} color="#6C9800" 
                    onPress={()=>{
                        auth.setisLogged(false);
                        auth.setcurrentUser({});
                    }}/>}
                    />
                    
                        <PostWrite user={auth.currentUser} />
                        <FlatList
                        data={posts}
                        onRefresh={getPosts}
                        refreshing={reload}
                        renderItem={function ({ item }) {
                            return (
                            <ShowPost
                                content={item}
                                currentuser={auth.currentUser}
                                navigation={navigation}
                            />
                            );
                        }}
                        keyExtractor={(item, index) => index.toString()}
                        />
                </View>
                
            )}
        </AuthContext.Consumer>
    );
}

const styles=StyleSheet.create({
    container:{
        flex:1,
        justifyContent: "center",
        
    },
});

export default HomeScreen;