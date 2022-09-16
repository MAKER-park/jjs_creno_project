import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:streaming/strm.dart';
import 'dart:convert';
import 'package:http/http.dart' as http;
import 'login.dart';

void main() async
{
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      debugShowCheckedModeBanner: false,
      home: MainPage(),
    );
  }
}

class MainPage extends StatefulWidget {
  @override
  _MainPage createState() => _MainPage();
}

class _MainPage extends State<MainPage> {
  bool clickbtn = true;


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black45,
      body: SafeArea(
        child: Stack(
          children: [
            Align(
              alignment: AlignmentDirectional(-0.88, -0.98),
              child: Image.asset(
                'images/server.png',
                width: 70,
                height: 70,
              ),
            ),
            Align(
              alignment: AlignmentDirectional(0.35, -0.92),
              child: Text(
                'JJJS streaming',
                style: TextStyle(fontSize: 40, color: Colors.white),
              ),
            ),
            Align(
              alignment: AlignmentDirectional(0, 0.9),
              child: InkWell(
                child: Image.asset(
                  'images/live.png',
                  width: 80,
                  height: 80,
                ),
                onTap: () {
                  clickbtn = !clickbtn;
                  Navigator.push(context,
                      CupertinoPageRoute(builder: (context) => Login())
                  );
                },
              ),
            ),
          ],
        ),
      ),
    );
  }
}
