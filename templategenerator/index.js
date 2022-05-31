const fs = require("fs");

let inputFile = fs.readFileSync("input.txt", "utf-8");

function convertInputText(input)
{
    
    while(input.includes(" *"))
    {
        input = input.replace(" *", "*");
    }

    console.log(input);

    const parts = input.split(" ");

    for(const p of parts)
    {
        console.log("PART: " + p);
    }

    const returnType = parts[1].replace(",", "");
    const className = parts[2].split("_")[0];
    const methotName = parts[2].split("_")[1].replace(",", "");

    console.log("RETURN: " + returnType);
    console.log("CLASS: " + className);
    console.log("METHOD: " + methotName);

    const startArgsIndex = input.indexOf("(", input.indexOf("(") + 1);
    const endArgsIndex = input.indexOf(")") + 1;
    const argsStr = input.slice(startArgsIndex + 1, endArgsIndex - 1);

    console.log("startArgsIndex: " + startArgsIndex);
    console.log("argsStr: " + argsStr);

    const args = argsStr.split(", ").map(arg => arg.split(" ")[0]);
    for(const a of args)
    {
        console.log("arg: " + a);
    }

    let coutStr = "";
    let defArgsStr = '';
    let fnArgsStr = '';
    let originStr = '';
    let i = 0;
    for(const a of args)
    {
        let char = String.fromCharCode(65 + i).toLowerCase();
        if(a.includes("MethodInfo")) char = "method";

        let delimiter = i != args.length-1 ? ", " : "";;

        fnArgsStr += `${a} ${char}`;
        fnArgsStr += delimiter

        defArgsStr += `${a}`
        defArgsStr += delimiter

        if(!a.includes("MethodInfo"))
        {
            if(i != 0) coutStr += "<<";

            coutStr += ` " ${char}=" << ${char} << "${delimiter}"`;
        }

        originStr += `${char}${delimiter}`;

        i++;
    }
    console.log("\nfnArgsStr:\n" + fnArgsStr);
    console.log("\ncoutStr:\n" + coutStr);

    let output = "";
    output += `auto HF_${className}_${methotName} = new HookFunction<${defArgsStr}>("${className}::${methotName}");\n`;
    output += `void Template_${className}_${methotName}(${fnArgsStr})\n`;
    output += `{\n`;
    output += `	std::cout << "${className}::${methotName}" << ${coutStr} << std::endl;\n`;
    output += `	\n`;
    output += `	HF_${className}_${methotName}->original(${originStr});\n`
    output += `}`;
    output += `	\n`;
    output += `	\n`;
    output += `Injector::Inject(HF_${className}_${methotName}, ${className}_${methotName}, &Template_${className}_${methotName});\n`;

    console.log("\noutput:\n" + output);

    return output;
}

let outputFile = '';

const parts = inputFile.split("\n");
for (const p of parts) {
    outputFile += convertInputText(p);
    outputFile += `\n\n`;
}

fs.writeFileSync("output.txt", outputFile);