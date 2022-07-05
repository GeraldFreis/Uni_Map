import Image from 'next/image'


export default function  ImageLoader () {
    return(
        <div className = 'image' style ={{display:'flex', justifyContent:'center'}}>
            <Image
            src = '/North_campus_map.png'
            width = '1000px'
            height = '1000px'
            />
        </div>
    )

    }