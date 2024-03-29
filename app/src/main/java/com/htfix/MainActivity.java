package com.htfix;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
public class MainActivity extends Activity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
    }

    private void initView() {
        findViewById(R.id.hook).setOnClickListener(this);
        findViewById(R.id.hook_cany).setOnClickListener(this);
        findViewById(R.id.start_activity).setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.hook) {
        } else if (v.getId() == R.id.start_activity) {
            startActivity();
        } else if (v.getId() == R.id.hook_cany) {
            hookCany();
        }
    }

    private void startActivity() {
        Intent intent = new Intent(this, InputConnectionActivity.class);
        this.startActivity(intent);
    }

    private void hookCany() {
    }

}
