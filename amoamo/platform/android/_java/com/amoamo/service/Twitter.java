package com.amoamo.service;

//import android.net.Uri;
import android.util.Log;
import android.os.Bundle;
import android.content.Intent;

import org.cocos2dx.lib.Cocos2dxActivity;

public abstract class Twitter
{
    private static final Cocos2dxActivity activity = (Cocos2dxActivity)Cocos2dxActivity.getContext();
    
    /*
    public static void onOpenURL(String msg)
    {
        Log.i ("INFO", "Start testApp:onOpenURL() URL[" + msg + "]");
        Uri uri = Uri.parse(msg);
        Intent i = new Intent(Intent.ACTION_VIEW, uri);
        activity.startActivity(i);
    }
    */
    
    public static void tweet(String msg){
        Log.i ("INFO", "####### Start Twitter::tweet("+msg+")");
        /*
         Intent intent = new Intent();
        intent.setAction(Intent.ACTION_SEND);
        intent.setType("text/plain");
        intent.putExtra(Intent.EXTRA_TEXT, msg);
        activity.startActivity(intent);
         */
    }
}
