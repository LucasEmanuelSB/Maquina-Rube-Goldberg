import 'package:audioplayers/audio_cache.dart';
import 'package:flutter/material.dart';
import 'package:material_design_icons_flutter/material_design_icons_flutter.dart';
import 'package:audioplayers/audioplayers.dart';

class Home extends StatefulWidget {
  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {

  AudioPlayer audioPlayer = AudioPlayer();
  AudioCache audioCache = AudioCache();

  _bigButton() async {
    
      audioPlayer = await audioCache.play("wakeUp.mp3");


    /* String url = "https://pic.pikbest.com/00/22/32/57e888piCYAS.mp3";
    int result;
    try {
      result = await audioPlayer.play(url);
    } catch (error) {
      print(result);
    } */
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Padding(
          padding: EdgeInsets.all(32),
          child: RaisedButton(
            shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.circular(50.0),
                side: BorderSide(color: Colors.blueAccent)),
            elevation: 5,
            color: Colors.blue,
            onPressed: () async {
              await _bigButton();
            },
            onLongPress: () async {
              await _bigButton();
            },
            child: Container(
                width: MediaQuery.of(context).size.width,
                height: MediaQuery.of(context).size.height,
                child: Icon(
                  MdiIcons.alarmSnooze,
                  size: 300,
                  color: Colors.yellow,
                )),
          ),
        ),
      ),
    );
  }
}
