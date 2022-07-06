import Image from 'next/image'


export default function  ImageLoader () {
    return(
        <div className = 'image' style ={{display:'flex', justifyContent:'center',
                                            maxWidth: '100', width: 'auto', height: 'auto'}}>
            <button onClick={get('./Node/a.out')} >
                <Image
                src = '/North_Campus_Map.png'
                width = '1500px'
                height = '1500px'
                />
            </button>
        </div>
    )

    }