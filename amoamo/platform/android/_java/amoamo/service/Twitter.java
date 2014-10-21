package amoamo.service;

//import android.net.Uri;
import android.util.Log;
import android.os.Bundle;
import android.content.Intent;

import org.cocos2dx.lib.Cocos2dxActivity;

public abstract class Twitter
{
    private static final Cocos2dxActivity activity = (Cocos2dxActivity)Cocos2dxActivity.getContext();
    
    public static void tweet(String msg){
        Intent intent = new Intent();
        intent.setAction(Intent.ACTION_SEND);
        intent.setType("text/plain");
        intent.putExtra(Intent.EXTRA_TEXT, msg);
        activity.startActivity(intent);
    }
}
