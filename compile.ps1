write-host "Compiling jcc compiler"
Invoke-Expression "gcc -o jcc.exe main.c"

if ($LASTEXITCODE -eq 0)
{
    write-host "Zipping to jcc.zip"
    Compress-Archive -Path jcc.exe -Destination jcc.zip -force
}
