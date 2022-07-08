import Image from 'next/image'


document.addEventListener('mousemove', (event) => {
	console.log(`Mouse X: ${event.clientX}, Mouse Y: ${event.clientY}`);
});




export default function  ImageLoader () {
    return(
        <div className = 'image' style ={{display:'flex', justifyContent:'center',
                                            maxWidth: '100', width: 'auto', height: 'auto'}}>
            <button onClick={console.log("Clicked")} >
                <Image
                src = '/North_Campus_Map.png'
                width = '1500px'
                height = '1500px'
                />
            </button>
        </div>
    )

    }