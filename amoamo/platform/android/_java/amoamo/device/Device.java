package amoamo.device;

//import android.net.Uri;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import android.util.Log;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.content.Context;
import android.content.Intent;

import org.cocos2dx.lib.Cocos2dxActivity;

public abstract class Device
{
    //private static final Cocos2dxActivity activity = (Cocos2dxActivity)Cocos2dxActivity.getContext();
    public static boolean isConnectedInternet()
    {
    	return true;
    	/*
        ConnectivityManager connectivity = (ConnectivityManager) NativeUtility.getMainActivity().getApplicationContext().
        getSystemService(Context.CONNECTIVITY_SERVICE);
        if (connectivity != null)
        {
            NetworkInfo[] info = connectivity.getAllNetworkInfo();
            if (info != null)
                for (int i = 0; i < info.length; i++)
                    if (info[i].getState() == NetworkInfo.State.CONNECTED)
                    {
                        return true;
                    }
        }
        return false;
        */
    }
}
