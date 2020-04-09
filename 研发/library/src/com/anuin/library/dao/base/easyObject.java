package src.com.anuin.library.dao.base;

public class easyObject {
    /**
     * 查询数量操作
     */
    public static int count(String chart,String name1,String value1,Class T1,String name2,String value2,Class T2){
        if(T1==Integer.class&&T2==Integer.class) {
            return Integer.parseInt(dataBase.queryForObject(
                    "select count(*) from " + chart + " where " + name1 + "=" + value1 + " and " + name2 + "=" + value2
                    , Integer.class));
        }else if(T1==Integer.class&&T2==String.class) {
            return Integer.parseInt(dataBase.queryForObject(
                    "select count(*) from " + chart + " where " + name1 + "=" + value1 + " and " + name2 + "='" + value2+"'"
                    , Integer.class));
        }else if(T1==String.class&&T2==Integer.class) {
            return Integer.parseInt(dataBase.queryForObject(
                    "select count(*) from " + chart + " where " + name1 + "='" + value1 + "' and " + name2 + "=" + value2
                    , Integer.class));
        }else if (T1==String.class&&T2==String.class) {
            return Integer.parseInt(dataBase.queryForObject(
                    "select count(*) from " + chart + " where " + name1 + "='" + value1 + "' and " + name2 + "='" + value2+"'"
                    , Integer.class));
        }else {
            return 0;
        }
    }

    public static int count(String chart,String name1,String value1,Class T1){
        if (T1==Integer.class) {
            return Integer.parseInt(dataBase.queryForObject(
                    "select count(*) from " + chart + " where " + name1 + "=" + value1
                    , Integer.class));
        }else {
            return Integer.parseInt(dataBase.queryForObject(
                    "select count(*) from " + chart + " where " + name1 + "='" + value1+"'"
                    , Integer.class));
        }
    }

    /**
     * 查询最大值操作
     */
    public static Integer max(String chart,String name1){
        String i = dataBase.queryForObject(
                "select max(" + name1 + ") from " + chart
                , Integer.class);
        if(i==null)
            return 0;
        else
            return Integer.parseInt(i);
    }

    /**
     * evaluate简易增加
     */

}
