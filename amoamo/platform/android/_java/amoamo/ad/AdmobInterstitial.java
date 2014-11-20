package amoamo.ad;

import org.cocos2dx.cpp.AppActivity;

import com.google.android.gms.ads.AdListener;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.InterstitialAd;

public class AdmobInterstitial {
    
	private static final AdmobInterstitial instance = new AdmobInterstitial();
	
    private static InterstitialAd interstitial = null;
    
    private AppActivity appActivity = null;
    private String adUnitId = null;
    
    private boolean isReady = false;
    
    private AdmobInterstitial(){}
    
    public static AdmobInterstitial getInstance(){
    	return AdmobInterstitial.instance;
    }
    
    public AdmobInterstitial setAppActivity(AppActivity appActivity) {
    	this.appActivity = appActivity;
    	return this;
    }
    
    public AdmobInterstitial setAdUnitId(String adUnitId) {
    	this.adUnitId = adUnitId;
    	return this;
    }
    
    public AdmobInterstitial init() {
    	isReady = false;
    	return this;
    }
    
    public void load() {
    	this.appActivity.runOnUiThread(new Runnable() {
    		public void run() {
    	    	isReady = false;
    		    interstitial = new InterstitialAd(appActivity);
    		    interstitial.setAdUnitId(adUnitId);
    		    AdRequest adRequest = new AdRequest.Builder().build();
    		    interstitial.setAdListener(new AdListener() {
				  @Override
				  public void onAdClosed() {
					load();
				  }
    		    });
    		    interstitial.loadAd(adRequest);
    		}
    	});
    }

    public void show() {
    	if (interstitial == null) {
    		return;
    	}
    	this.appActivity.runOnUiThread(new Runnable() {
    		public void run() {
		        if (interstitial.isLoaded()) {
		            interstitial.show();
		        }
    		}
    	});
    }
    
    private void checkReady() {
    	if (interstitial == null) {
    		return;
    	}
    	this.appActivity.runOnUiThread(new Runnable() {
    		public void run() {
    			isReady = interstitial.isLoaded();
    		}
    	});
    }

    public boolean isReady() {
    	checkReady();
    	return isReady;
    }
    
    public void destroy() {
        if (interstitial == null) {
        	return;
        }
        interstitial = null;
    }
    
    // for jni
    
    public static void jniInit(String adUnitId) {
        AdmobInterstitial.getInstance().setAdUnitId(adUnitId).load();
    }

    public static boolean jniIsReady() {
    	return AdmobInterstitial.getInstance().isReady();
    }

    public static void jniShow() {
    	AdmobInterstitial.getInstance().show();
    }
}
