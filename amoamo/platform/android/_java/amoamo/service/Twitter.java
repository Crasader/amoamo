package amoamo.service;

//import android.net.Uri;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import android.util.Log;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.content.Intent;

import org.cocos2dx.lib.Cocos2dxActivity;

public abstract class Twitter
{
    private static final Cocos2dxActivity activity = (Cocos2dxActivity)Cocos2dxActivity.getContext();
    
    public static void tweet(String msg) {
        Intent intent = new Intent();
        intent.setAction(Intent.ACTION_SEND);
        intent.setType("text/plain");
        intent.putExtra(Intent.EXTRA_TEXT, msg);
        activity.startActivity(intent);
    }
    
    public static void tweetWithScreenShot(String msg, String file_path) {
        
        final String path = file_path;
        final String tweetMessage = msg;
        
        activity.runOnUiThread(new Runnable(){
            @Override
            public void run()
            {
                File f = new File(path);
                
                byte[] data;
                try
                {
                    data = readFileToByte(path);
                }
                catch(Exception e)
                {
                    Log.e("Debug", e.getMessage());
                    return;
                }
                
                File savePath = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
                File saveFile = new File(savePath,"screenshot.jpeg");
                
                if(!savePath.exists())
                {
                    savePath.mkdir();
                }
                
                FileOutputStream fos = null;
                
                try
                {
                    fos = new FileOutputStream(saveFile);
                    fos.write(data);
                    fos.close();
                }
                catch(Exception e)
                {
                    Log.e("Debug", e.getMessage());
                    return ;
                }
                
                Uri uri = Uri.fromFile(saveFile);
                
                Intent it = new Intent(Intent.ACTION_SEND);
                it.putExtra(Intent.EXTRA_SUBJECT, "");
                it.putExtra(Intent.EXTRA_TEXT, tweetMessage);
                it.putExtra(Intent.EXTRA_STREAM,uri);
                it.setType("image/jpeg");
                
                activity.startActivity(Intent.createChooser(it,"share"));
            }
        });
    }
    
    private static byte[] readFileToByte(String filePath) throws Exception {
        byte[] b = new byte[1];
        FileInputStream fis = new FileInputStream(filePath);
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        while (fis.read(b) > 0) {
            baos.write(b);
        }
        baos.close();
        fis.close();
        b = baos.toByteArray();
        
        return b;
    }
}
