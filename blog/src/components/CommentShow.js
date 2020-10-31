import React from "react";
import {Card,CardItem, Body} from 'native-base';
import { Text } from "react-native";

const ShowComment=({content})=>{
    return(
        <Card>
            <CardItem bordered>
                <Text style={{fontWeight:'bold'}}>{content.sender}</Text>
                </CardItem>
            <CardItem>
                <Body>
                    <Text>
                        {content.comment}
                    </Text>
                </Body>
            </CardItem>
        </Card>
    );
}

export default ShowComment;