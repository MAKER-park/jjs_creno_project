import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter_hooks/flutter_hooks.dart';
import 'package:flutter_mjpeg/flutter_mjpeg.dart';

import 'main.dart';

class StrmBar extends HookWidget {
  @override
  Widget build(BuildContext context) {
    final isRunning = useState(true);

    return Scaffold(
      backgroundColor: Colors.black38,
      body: SafeArea(
        child: Stack(
          children: [
            Align(
              alignment: AlignmentDirectional(0, 0.92),
              child: InkWell(
                  child: Image.asset('images/home.png',
                      width: 60,
                      height: 60,
                      alignment: AlignmentDirectional(0, 1)),
                  onTap: () {
                    Navigator.push(context,
                        CupertinoPageRoute(builder: (context) => MainPage()));
                  }),
            ),
            Align(
              alignment: AlignmentDirectional(0, -1),
              child: SingleChildScrollView(
                child: Column(
                  mainAxisSize: MainAxisSize.max,
                  mainAxisAlignment: MainAxisAlignment.spaceAround,
                  crossAxisAlignment: CrossAxisAlignment.center,
                  children: [
                    Mjpeg(   // Mjpeg 라이브러리 함수 호출
                      isLive: isRunning.value,   // 주소와 원활하게 통신해서 영상 출력이 가능한지 확인
                      error: (context, error, stack) {   // 에러 메시지 
                        print(error);
                        print(stack);
                        return Text(error.toString(),
                            style: TextStyle(color: Colors.red));
                      },
                      stream: 'http://10.10.141.250:8080/?action=stream', // 영상 송출할 스트리밍 주소 선언
                    ),
                    Mjpeg(
                      isLive: isRunning.value,
                      error: (context, error, stack) {
                        print(error);
                        print(stack);
                        return Text(error.toString(),
                            style: TextStyle(color: Colors.red));
                      },
                      stream: 'http://10.10.141.250:8081/?action=stream',
                    ),
                  ],
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
