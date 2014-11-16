package amoamo.ad;

import org.cocos2dx.cpp.AppActivity;
import android.graphics.Color;
import android.view.Gravity;
import android.view.View;
import android.widget.FrameLayout;
import android.widget.LinearLayout;

import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdView;

public class AdmobInterstitial {
    
	private static final AdmobBanner instance = new AdmobBanner();
	
    private static AdView adView = null;
    private static FrameLayout.LayoutParams adParams = null;
    
    private final static int lp = LinearLayout.LayoutParams.WRAP_CONTENT; 
    
    private AdmobBanner(){}
    
    public static AdmobBanner getInstance(){
    	return AdmobBanner.instance;
    }
    
    public void init(AppActivity appActivity, String adUnitId) {
    	if (adView != null) {
    		return;
    	}
        adView = new AdView(appActivity);
        adView.setAdSize(AdSize.BANNER);
        adView.setBackgroundColor(Color.TRANSPARENT);
        adView.setAdUnitId(adUnitId);
        
        adParams = new FrameLayout.LayoutParams(lp, lp);
        adParams.gravity = (Gravity.BOTTOM|Gravity.CENTER);
    }
    
    public void load() {
        AdRequest adRequest = new AdRequest.Builder()
            .addTestDevice(AdRequest.DEVICE_ID_EMULATOR)
            .build();
        adView.loadAd(adRequest);
    }
    
    public AdView getAdView() {
    	return adView;
    }
    
    public FrameLayout.LayoutParams getAdParams() {
    	return adParams;
    }

    public void hide() {
        if (adView.getVisibility() == AdView.VISIBLE) {
            adView.setVisibility(View.GONE);
        }
    }

    public void show() {
        adView.setVisibility(View.VISIBLE);;
    }
    
    public void destroy() {
        if(adView == null){
        	return;
        }
        adView.destroy();
        adView = null;
    }
    
    // for jni

    public static void jni_hide() {
        AdmobBanner.getInstance.hide();
    }

    public static void jni_show() {
        AdmobBanner.getInstance.show();
    }
}
