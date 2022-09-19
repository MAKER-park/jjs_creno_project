import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:streaming/strm.dart';

class Login extends StatefulWidget {
  @override
  _Login createState() => _Login();
}

class _Login extends State<Login> {
  final formKey = new GlobalKey<FormState>();
  String password = "250";       // String형 패스워드 설정 "250"으로 초기화

  String get value => "250";     // if문에 사용하기위해 값을 password와 동일시함

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Form(
        key: formKey,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceAround,
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Padding(
                padding: const EdgeInsets.fromLTRB(20, 20, 20, 20),
                child: Column(
                  children: [
                    const Text(
                      'password',
                      style: TextStyle(
                        fontSize: 25.0,
                      ),
                    ),
                    TextFormField(
                        autovalidateMode: AutovalidateMode.always,
                        onSaved: (value) {
                          setState(() {
                            password = value as String;
                          });
                        },
                        validator: (value) {
                          if (value == null || value.isEmpty) {  // 비밀번호 입력 값이 null(공백) 상태 일시 비밀번호를 입력하라는 메시지 발생
                            return 'Please Enter Some Password';
                          }
                          if (!RegExp('[0-9]').hasMatch(value)) { // 비밀번호 자릿수를 최대 9자리로 설정
                            return 'MAX';
                          }
                          return null;
                        }),
                    ElevatedButton(
                      onPressed: () { 
                        if (formKey.currentState!.validate()) {
                          formKey.currentState!.save();

                          // If the form is valid, display a SnackBar. In the real world,
                          // you'd often call a server or save the information in a database.
                        }
                        if (password == value) {  // password(설정 비밀번호) "250" value(입력 비밀번호) "250" 둘다 같으면 스트리밍 화면으로 넘어감
                          Navigator.push(
                              context,
                              CupertinoPageRoute(
                                  builder: (context) => StrmBar()));
                          ScaffoldMessenger.of(context).showSnackBar(
                              SnackBar(content: Text('Connected')));
                        }
                        if (password != value)   // password와 value 가 틀렸을 경우 틀린걸 알려주는 메시지 출력
                        {
                          ScaffoldMessenger.of(context).showSnackBar(
                              SnackBar(content: Text('Wrong Password')));
                        }
                      },
                      child: const Text('Connect'),
                    ),
                  ],
                )),
          ],
        ),
      ),
    );
  }
}
