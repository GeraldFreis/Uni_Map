import Image from 'next/image'
import React from 'react';

const useMousePosition = () => {
  const [
    mousePosition,
    setMousePosition
  ] = React.useState({ x: null, y: null });
  
  React.useEffect(() => {
    const updateMousePosition = ev => {
      setMousePosition({ x: ev.clientX, y: ev.clientY });
    };
    window.addEventListener('mousemove', updateMousePosition);
    return () => {
      window.removeEventListener('mousemove', updateMousePosition);
    };
  }, []);
  return mousePosition;
};

document.addEventListener('mousemove', (event) => {
	console.log(`Mouse X: ${event.clientX}, Mouse Y: ${event.clientY}`);
});




export default function  ImageLoader () {
    return(
        <div className = 'image' style ={{display:'flex', justifyContent:'center',
                                            maxWidth: '100', width: 'auto', height: 'auto'}}>
            <button onClick={console.log(useMousePosition())} >
                <Image
                src = '/North_Campus_Map.png'
                width = '1500px'
                height = '1500px'
                />
            </button>
        </div>
    );

}