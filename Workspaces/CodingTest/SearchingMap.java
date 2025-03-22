import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;
public class SearchingMap {
        public static void main(String[] args) throws IOException{
            
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
            int n = Integer.parseInt(br.readLine());

            String [] map1 = new String[n];
            String [] map2 = new String[n];

            StringTokenizer st1 = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            
            String [] findMap = new String[n]; 
            
            for(int i=0; i<n;i++){
                int num1 = Integer.parseInt(st1.nextToken());
                String Binarynum1 = Integer.toBinaryString(num1);
                map1[i] = Binarynum1;

                int num2 = Integer.parseInt(st2.nextToken());
                String Binarynum2 = Integer.toBinaryString(num2);
                map2[i] = Binarynum2;
                String map3code = "";


                for(int j=0; j<n; j++){
                    char code1=' ';
                    char code2=' ';
                    char code3=' ';
                    int index1 = (Binarynum1.length()-n)+j;
                                //111이라면 3-5+j, -2 -1 0 1 2
                    if(index1<0){
                        code1 = '0';//2번
                    }
                    else{
                        code1 = Binarynum1.charAt(index1);//3번, 0 1 2
                    }

                    int index2 = (Binarynum2.length()-n)+j;

                    if(index2<0){
                        code2 = '0';
                    }
                    else{
                        code2 = Binarynum2.charAt(index2);
                    }

                    if(code1==code2){
                        if(code1=='0'){
                            code3 = '0';
                        }
                        else{
                            code3 = '#';
                        }
                    }
                    else{
                        code3 = '-';
                    }
                    map3code +=code3;
                }

                findMap[i] = map3code;
                System.out.println(map3code);

            }


        }
}
