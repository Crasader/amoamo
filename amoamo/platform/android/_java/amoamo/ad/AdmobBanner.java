package amoamo.ad;

import org.cocos2dx.cpp.AppActivity;
import android.graphics.Color;
import android.view.Gravity;
import android.widget.FrameLayout;
import android.widget.LinearLayout;

import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdView;

public class AdmobBanner {
    
	private static final AdmobBanner instance = new AdmobBanner();
	
    private AdView adView = null;
    private FrameLayout.LayoutParams adParams = null;
    
    private AppActivity appActivity = null;
    private String adUnitId = null;
    
    private final static int lp = LinearLayout.LayoutParams.WRAP_CONTENT; 
    
    private AdmobBanner(){}
    
    public static AdmobBanner getInstance(){
    	return AdmobBanner.instance;
    }
    
    public void load() {
    	appActivity.runOnUiThread(new Runnable() {
    		public void run() {
    	        adView.setAdSize(AdSize.BANNER);
    	        adView.setBackgroundColor(Color.TRANSPARENT);
    	        adParams.gravity = (Gravity.BOTTOM|Gravity.CENTER);
    	        adView.setAdUnitId(adUnitId);
    	        AdRequest adRequest = new AdRequest.Builder()
    		        .addTestDevice(AdRequest.DEVICE_ID_EMULATOR)
    		        .build();
    	        adView.loadAd(adRequest);
    		}
    	});
    }
    
    public AdmobBanner init() {
        adView = new AdView(appActivity);
        adParams = new FrameLayout.LayoutParams(lp, lp);
        return this;
    }
    
    public AdmobBanner setAppActivity(AppActivity appActivity) {
    	this.appActivity = appActivity;
    	return this;
    }
    
    public AdmobBanner setAdUnitId(String adUnitId) {
    	this.adUnitId = adUnitId;
    	return this;
    }
    
    public AdView getAdView() {
    	return adView;
    }
    
    public FrameLayout.LayoutParams getAdParams() {
    	return adParams;
    }

    public void hide() {
        if (adView.getVisibility() == AdView.VISIBLE) {
        	appActivity.runOnUiThread(new Runnable() {
        		public void run() {
		            adView.setVisibility(AdView.GONE);
		            adView.pause();
        		}
        	});
        }
    }

    public void show() {
        //if (adView.getVisibility() == AdView.GONE) {
	    	appActivity.runOnUiThread(new Runnable() {
	    		public void run() {
			        adView.setVisibility(AdView.VISIBLE);
			        adView.resume();
	    		}
	    	});
        //}
    }
    
    public void destroy() {
        if(adView == null){
        	return;
        }
        adView.destroy();
        adView = null;
    }
    
    // for jni

    public static void jniInit(String adUnitId) {
        AdmobBanner.getInstance().setAdUnitId(adUnitId).load();
    }
    
    public static void jniHide() {
        AdmobBanner.getInstance().hide();
    }

    public static void jniShow() {
        AdmobBanner.getInstance().show();
    }
}
