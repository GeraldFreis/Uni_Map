import React from "react"
import Image from "next/image"
import ImageLoader from "./image_loader";

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
               <ImageLoader/>
        </div>
    );
}