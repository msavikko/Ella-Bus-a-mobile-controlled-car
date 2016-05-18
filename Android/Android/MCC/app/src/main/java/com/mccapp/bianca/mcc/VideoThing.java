package com.mccapp.bianca.mcc;

import android.app.Activity;
import android.os.Bundle;

/**
 * Created by group 8 on 2016-05-17.
 */

public class VideoThing extends Activity {
/**    private static VideoThing ourInstance = new VideoThing();

    public static VideoThing getInstance() {
        return ourInstance;
    }

    private VideoThing() {
    }
*/
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.video);
    }

}
