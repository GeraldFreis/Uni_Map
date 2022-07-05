import React from "react"
import Image from "next/image"

const Container = React.forwardRef((props, ref) => {
    return (
        <div ref={ref} style={{ overflowX: 'scroll', width: '500px' }} >
            {props.children}
        </div>
    );
} )


export default function Body () {
    const lazyRoot = React.useRef(null)

    return (
        <div className="Body">
            <div className="Image" style={{display: 'flex'}}>
               {/* <Container ref={lazyRoot}>
                    <Image lazyRoot={lazyRoot} src="/North_campus_map.png" width="500" height="500" /> 
               </Container> */}
               <MyImage />
            </div>
        </div>
    );
}