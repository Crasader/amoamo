Ad reference
====

## Admob
###Admob Banner

- on `.cpp` code
```c
amoamo::ad::AdmobBanner::getInstance()->
    init("ca-app-pub-****/****");
amoamo::ad::AdmobBanner::getInstance()->hideAd();
amoamo::ad::AdmobBanner::getInstance()->showAd();
```

- on `AppActivity.java`
```java
    @SuppressLint("NewApi")
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        # add this
        AdmobBanner admob = AdmobBanner.getInstance();
        admob.setAppActivity(this).init();
        addContentView(admob.getAdView(), admob.getAdParams());
    }
```


###Admob Interstitial

- on `.cpp` code
```c
amoamo::ad::AdmobInterstitial::getInstance()->
    init("ca-app-pub-8451216461217892/9929816802");
if (amoamo::ad::AdmobInterstitial::getInstance()->isReady()) {
    amoamo::ad::AdmobInterstitial::getInstance()->showAd();
}
```

- on `AppActivity.java`
```java
    @SuppressLint("NewApi")
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        # add this
        AdmobInterstitial interstitial = AdmobInterstitial.getInstance();
        interstitial.setAppActivity(this).init();
    }
```
