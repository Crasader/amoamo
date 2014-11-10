package amoamo.ad;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.annotation.TargetApi;
import android.graphics.Color;
import android.graphics.Point;
import android.os.Build;
import android.os.Bundle;
import android.view.Display;
import android.view.View;
import android.view.WindowManager;
import android.widget.LinearLayout;

import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdView;

public abstract class AdmobBanner
{
    private static final Cocos2dxActivity activity = (Cocos2dxActivity)Cocos2dxActivity.getContext();
    
    public static void init() {
        adView = new AdView(this);
        adView.setAdSize(AdSize.BANNER);
        adView.setAdUnitId("ca-app-pub-から始まる広告ユニットIDをここに");
        
        FrameLayout.LayoutParams adParams = new FrameLayout.LayoutParams(lp,lp);
        adParams.gravity = (Gravity.BOTTOM|Gravity.CENTER);
        addContentView(adView, adParams);
        
        AdRequest adRequest = new AdRequest.Builder().build();
        
        adView.loadAd(adRequest);
    }
}
