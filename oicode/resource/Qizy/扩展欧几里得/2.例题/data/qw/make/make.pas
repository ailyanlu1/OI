// ��������makedata
// ���ܣ�����EXE�Զ�������������
// ���ߣ�����ʤ

program make;
uses
  dos;
const
  filename= 'qw';            //�ļ���,��ͬ����˴���Ҫ�޸�
  fileexe=  filename+'.exe';  //��̿�ִ���ļ���
  filein= filename+'.in';     //��׼�����ļ�
  fileout=filename+'.out' ;   //��׼����ļ�

var
  f,ff:text;               //�ļ�����
  m1,n1,x1,y1,l1,n,i,j,a,b,c :longint;
  nn:array[1..10] of longint=(30,50,80,100,2000,30000,400000,500000,6000000,70000000);  //10�������ļ��ķ�Χ
  m,min,mout:string;

begin
  for n:=1 to 10 do begin  //ѭ��10��,���β���10���������
    str(n,m); // �õ�1���ļ����
    min:=filename+m+'.in';  //�����m�������ļ���
    mout:=filename+m+'.out';  //�����m������ļ���

    assign(output,filein);rewrite(output);  //������׼�����ļ�

//--------------  ��ͬ��Ŀ��ֻ��Ҫ�޸Ĵ˴� -------------------------------------

   // writeln(nn[n]);  //�������ļ���һ��д�뱾�������ļ���nֵ
    randomize;
    l1:=random(nn[n]);
    x1:=random(l1 div 2);
    y1:=random(l1 div 2);
    m1:=random(nn[n]);
    if m1>100 then m1:=m1 div 100
      else if m1>1 then m1:=m1 div 10;
    n1:=random(nn[n] div 2);
    if n1>100 then n1:=n1 div 100
      else if n1>10 then n1:=n1 div 10;

    write(x1,' ',y1,' ',m1,' ',n1,' ',l1);
    writeln;
//-----------------------------------------------------------------------------

    close(output);    //�ر��ļ���,����1����׼�����ļ�*.in
    exec(fileexe,''); //���ò�ִ���ⲿ��׼exe����,����1����׼����ļ�*.out

    assign(f,filein);
    rename(f,min);    //�����ļ��������������

    assign(ff,fileout);
    rename(ff,mout);  //����ļ��������������
  end;
end.




