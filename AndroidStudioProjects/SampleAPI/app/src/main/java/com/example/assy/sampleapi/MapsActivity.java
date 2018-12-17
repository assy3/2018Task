package com.example.assy.sampleapi;

import android.support.v4.app.FragmentActivity;
import android.os.Bundle;
import com.google.android.gms.maps.CameraUpdate;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

public class MapsActivity extends FragmentActivity implements OnMapReadyCallback {

    private GoogleMap mMap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);
    }


    /**
     * Manipulates the map once available.
     * This callback is triggered when the map is ready to be used.
     * This is where we can add markers or lines, add listeners or move the camera. In this case,
     * we just add a marker near Sydney, Australia.
     * If Google Play services is not installed on the device, the user will be prompted to install
     * it inside the SupportMapFragment. This method will only be triggered once the user has
     * installed Google Play services and returned to the app.
     */
    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;

        // Add a marker in Sydney and move the camera
        LatLng marker0 = new LatLng(36.582485, 136.67782);
        LatLng marker1 = new LatLng(36.542485, 136.73782);
        LatLng marker2 = new LatLng(36.566805, 136.636831);
        LatLng marker3 = new LatLng(36.525493, 136.697964);
        LatLng marker4 = new LatLng(36.596476, 136.653866);
        LatLng marker5 = new LatLng(36.543319, 136.674938);
        LatLng marker6 = new LatLng(36.594572, 136.717665);
        LatLng marker7 = new LatLng(36.604, 136.617534);
        LatLng marker8 = new LatLng(36.553626, 136.656055);
        LatLng marker9 = new LatLng(36.602153, 136.632586);
        LatLng marker10 = new LatLng(36.608707, 136.598972);
        LatLng marker11 = new LatLng(36.566951, 136.579401);
        LatLng marker12 = new LatLng(36.529476, 136.645712);

        mMap.addMarker(new MarkerOptions().position(marker1).title("戸室新保埋立場"));
        mMap.addMarker(new MarkerOptions().position(marker2).title("大豆田大橋詰"));
        mMap.addMarker(new MarkerOptions().position(marker3).title("館町"));
        mMap.addMarker(new MarkerOptions().position(marker4).title("磯部町"));
        mMap.addMarker(new MarkerOptions().position(marker5).title("城南中学校前犀川右岸"));
        mMap.addMarker(new MarkerOptions().position(marker6).title("金沢テクノパーク（北陽台３丁目地内）"));
        mMap.addMarker(new MarkerOptions().position(marker7).title("戸水２丁目"));
        mMap.addMarker(new MarkerOptions().position(marker8).title("【石川県】桜橋左岸下流"));
        mMap.addMarker(new MarkerOptions().position(marker9).title("鞍月小学校運動場"));
        mMap.addMarker(new MarkerOptions().position(marker10).title("金石小学校運動場"));
        mMap.addMarker(new MarkerOptions().position(marker11).title("安原小学校運動場"));
        mMap.addMarker(new MarkerOptions().position(marker12).title("富樫小学校運動場"));
        CameraUpdate cUpdate = CameraUpdateFactory.newLatLngZoom( new LatLng(36.55, 136.7), 11);
        // 倍率を地図に反映させる。
        mMap.moveCamera(cUpdate);
        mMap.moveCamera(CameraUpdateFactory.newLatLng(marker0));
    }
}
