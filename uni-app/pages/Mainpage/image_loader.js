import Image from 'next/image'


export default function  ImageLoader () {
    return(
        <div className = 'image' style ={{display:'flex', justifyContent:'center'}}>
            <Image
            src = '/North_Campus_Map.png'
            width = '1500px'
            height = '1500px'
            />
        </div>
    )

    }