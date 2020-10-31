import {AsyncStorage} from 'react-native';

const storeData = async (key, value) => {
  try {
    await AsyncStorage.setItem(key, value);
    console.log("Data Stored Successfully!");
  } catch (error) {
    console.log(error);
  }
};


const storeDataJSON = async (key, value) => {
  try {
    const jsonValue = JSON.stringify(value);
    await AsyncStorage.setItem(key, jsonValue);
    console.log("Data Stored Successfully!");
  } catch (error) {
    console.log(error);
  }
};

const getAllKeys = async()=>{
  let keys = []
  try {
    keys = await AsyncStorage.getAllKeys();
    return keys;
  } catch(e) {
     console.log(e)
  }
}


const mergeData=async(key,value)=>{
  try{
    await AsyncStorage.mergeItem(key,value);
    return true;
  }catch(e){console.log(e)}
};

const clear =async()=>{
  AsyncStorage.clear();
};


const getAllData = () =>{
  AsyncStorage.getAllKeys().then((keys) => {
    return AsyncStorage.multiGet(keys)
      .then((result) => {
        // console.log(result);
      }).catch((e) =>{
        console.log(e);
      });
  });
}

  

const getData = async (key) => {
  try {
    let data = await AsyncStorage.getItem(key);
    if (data != null) {
      return data;
    } else {
      console.log("No data with this key!");
    }
  } catch (error) {
    console.log(error);
  }
};

const getDataJSON = async (key) => {
  try {
    let data = await AsyncStorage.getItem(key);
    if (data != null) {
      const jsonData = JSON.parse(data);
      return jsonData;
    } else {
      return null;
    }
  } catch (error) {
    console.log(error);
  }
};

const removeData = async (key) => {
  try {
    await AsyncStorage.removeItem(key);
    return true;
  } catch (error) {
    console.log(error);
  }
};



export { mergeData,clear,getAllData,getAllKeys,storeData, storeDataJSON, getData, getDataJSON, removeData };