package amoamo.ad;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import org.cocos2dx.cpp.AppActivity;
import org.cocos2dx.lib.Cocos2dxActivity;

import android.annotation.SuppressLint;
import android.graphics.Color;
import android.graphics.Point;
import android.os.Bundle;
import android.view.Display;
import android.view.Gravity;
import android.widget.FrameLayout;
import android.widget.FrameLayout.LayoutParams;
import android.widget.LinearLayout;

import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdView;

public abstract class AdmobBanner extends Cocos2dxActivity {
    
    private static AdView adView = null;
    
    private final static int lp = LinearLayout.LayoutParams.WRAP_CONTENT; 
    
    public static void init(AppActivity appActivity, String adUnitId) {
    	if (adView != null) {
    		return;
    	}
        adView = new AdView(appActivity);
        adView.setAdSize(AdSize.BANNER);
        adView.setAdUnitId(adUnitId);
        
        FrameLayout.LayoutParams adParams = new FrameLayout.LayoutParams(lp, lp);
        adParams.gravity = (Gravity.BOTTOM|Gravity.CENTER);
        
        AdRequest adRequest = new AdRequest.Builder().addTestDevice(AdRequest.DEVICE_ID_EMULATOR).build();
        
        adView.loadAd(adRequest);
        
        //addContentView(adView, adParams);
    }
    
    public static void getAdView() {
    	
    }
    
    public static void getAdParams() {
    	
    }
}
