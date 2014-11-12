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
    private static FrameLayout.LayoutParams adParams = null;
    
    private final static int lp = LinearLayout.LayoutParams.WRAP_CONTENT; 
    
    public static void init(AppActivity appActivity, String adUnitId) {
    	if (adView != null) {
    		return;
    	}
        adView = new AdView(appActivity);
        adView.setAdSize(AdSize.BANNER);
        adView.setAdUnitId(adUnitId);
        
        adParams = new FrameLayout.LayoutParams(lp, lp);
        adParams.gravity = (Gravity.BOTTOM|Gravity.CENTER);
        
        AdRequest adRequest = new AdRequest.Builder()
            .addTestDevice(AdRequest.DEVICE_ID_EMULATOR)
            .build();
        
        adView.loadAd(adRequest);
    }
    
    public static AdView getAdView() {
    	return adView;
    }
    
    public static FrameLayout.LayoutParams getAdParams() {
    	return adParams;
    }

    public static void hide() {
        if (adView.getVisibility() == AdView.VISIBLE) {
            adView.setVisibility(View.GONE);
        }
    }

    public static void show() {
        return adView.setVisibility(View.VISIBLE);;
    }
}
