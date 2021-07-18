<#A guessing number game for powershell#>

$win = 0
$number = Get-Random -Minimum 1 -Maximum 10
do {
    $guess = Read-Host -Prompt "Enter a number to guess: "
    if ($guess -lt $number) {
        Write-Output "Too low!"
        $win = 1
    }
    else {
        Write-Output "Too high!"
        $win = 0
    }
}
while ($guess -ne $number)

if ($win = 1) {
    Write-Output "You Win!"
}
else {
    Write-Output "Try next time!"
}