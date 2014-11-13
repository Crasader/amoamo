Sample usage
====

````java
public class AppActivity extends Cocos2dxActivity {

    public Cocos2dxGLSurfaceView mGLView;

    @SuppressLint("NewApi")
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        AdmobBanner admob = AdmobBanner.getInstance();
        admob.init(this, "ca-app-pub-8451216461217892/8453083609");
        addContentView(admob.getAdView(), admob.getAdParams());
        admob.load();
    }

    public Cocos2dxGLSurfaceView onCreateView() {
        Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
        glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
        mGLView = glSurfaceView;
        return glSurfaceView;
    }

    protected void onDestroy(){
    	AdmobBanner.getInstance().destroy();
        super.onDestroy();
    }
}
````
