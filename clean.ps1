# clean.ps1 - Clean all .exe files

Write-Host "=== Searching for .exe files ===" -ForegroundColor Yellow
$files = Get-ChildItem -Path . -Filter *.exe -Recurse

if ($files.Count -eq 0) {
    Write-Host "No .exe files found" -ForegroundColor Green
    exit
}

Write-Host "Found $($files.Count) files:" -ForegroundColor Cyan
$files | ForEach-Object {
    Write-Host "  $($_.FullName)" -ForegroundColor White
}

Write-Host ""
$confirm = Read-Host "Confirm deletion? (y/n)"

if ($confirm -eq 'y' -or $confirm -eq 'Y') {
    $files | Remove-Item -Force
    Write-Host "`nAll .exe files deleted" -ForegroundColor Green
} else {
    Write-Host "`nCancelled" -ForegroundColor Yellow
}
