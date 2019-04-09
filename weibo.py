from bs4 import BeautifulSoup
import requests

headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:58.0) Gecko/20100101 Firefox/58.0'
}
user_cookie = 'SINAGLOBAL=5440873641171.115.1527320517815; UM_distinctid=166815eef3c6d3-070b1236b6aacb-3c7f0257-1fa400-166815eef3d346; UOR=www.techweb.com.cn,widget.weibo.com,www.google.com; SCF=AnI1N3m1GfdbD5FBcSfxQ5ovX3cRg-00tas7MAJwjWFAJ9WqVeaSeFYVuLVUHQGEUxypg3jEg1Llphw2wHw65OY.; SUB=_2A25xjILODeRhGeNP4lYQ-CnEwjuIHXVS-_MGrDV8PUJbmtBeLWvckW9NTkdMaUk6eSKKgdnVf-KM7EMnlK_IWVCR; SUBP=0033WrSXqPxfM725Ws9jqgMF55529P9D9W5fyEm6c.Z8MLaAbQigbAdm5JpX5K-hUgL.Fo-p1KBp1hMR1KM2dJLoI7UDMfvVdc4L; SUHB=0S7Ct_4Dhy-mmt; ALF=1584014875; SSOLoginState=1552478878; _s_tentry=login.sina.com.cn; Apache=52280691269.03323.1552478892920; ULV=1552478892927:3:1:1:52280691269.03323.1552478892920:1544684973487; S_ACCOUNT-G0=8078bc8dd956a1d514156c101b267383; SL_GWPT_Show_Hide_tmp=1; SL_wptGlobTipTmp=1; BL_D_PROV=; BL_T_PROV=; WBStorage=201903132026|undefined'
#将字符串转换为列表，请求中的cookie参数传递的是dict形式
def stringToDic(cookie_str):
    itemDict = {}
    items = cookie_str.split(';')
    for item in items:
        key = item.split('=')[0].replace(' ', '')
        value = item.split('=')[1]
        itemDict[key] = value
    return itemDict
def getPage():
    url = 'https://m.weibo.cn/statuses/show?id=G5kJf3ELY'
    cookie = stringToDic(user_cookie)
    response = requests.get(url=url,headers=headers)
    downloadPage(response.text)

def downloadPage(text):
    with open('main.html','w') as f:
        f.write(text)
        f.close()

if __name__ == "__main__":
    getPage()