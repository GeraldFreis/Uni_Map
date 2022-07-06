import Image from 'next/image'


export default function  ImageLoader () {
    return(
        <div className = 'image' style ={{display:'flex', justifyContent:'center',
                                            maxWidth: '100', width: 'auto', height: 'auto'}}>
            <Image
            src = '/North_Campus_Map.png'
            width = '1500px'
            height = '1500px'
            src = '/North_campus_map.png'
            width = '1500'
            height = '1500'
            />
        </div>
    )

    }