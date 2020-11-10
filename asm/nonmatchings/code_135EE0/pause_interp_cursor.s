.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_interp_cursor
/* 1361AC 80242E6C 3C0A8025 */  lui       $t2, %hi(gPauseMenuCursorPos)
/* 1361B0 80242E70 254AEF9C */  addiu     $t2, $t2, %lo(gPauseMenuCursorPos)
/* 1361B4 80242E74 3C058025 */  lui       $a1, %hi(gPauseMenuTargetPos)
/* 1361B8 80242E78 8CA5EFA8 */  lw        $a1, %lo(gPauseMenuTargetPos)($a1)
/* 1361BC 80242E7C 8D430000 */  lw        $v1, ($t2)
/* 1361C0 80242E80 3C013FE0 */  lui       $at, 0x3fe0
/* 1361C4 80242E84 44812800 */  mtc1      $at, $f5
/* 1361C8 80242E88 44802000 */  mtc1      $zero, $f4
/* 1361CC 80242E8C 00A31023 */  subu      $v0, $a1, $v1
/* 1361D0 80242E90 44821000 */  mtc1      $v0, $f2
/* 1361D4 80242E94 00000000 */  nop       
/* 1361D8 80242E98 468010A1 */  cvt.d.w   $f2, $f2
/* 1361DC 80242E9C 46241082 */  mul.d     $f2, $f2, $f4
/* 1361E0 80242EA0 00000000 */  nop       
/* 1361E4 80242EA4 3C098025 */  lui       $t1, 0x8025
/* 1361E8 80242EA8 2529EFA0 */  addiu     $t1, $t1, -0x1060
/* 1361EC 80242EAC 3C048025 */  lui       $a0, 0x8025
/* 1361F0 80242EB0 8C84EFAC */  lw        $a0, -0x1054($a0)
/* 1361F4 80242EB4 8D260000 */  lw        $a2, ($t1)
/* 1361F8 80242EB8 00861023 */  subu      $v0, $a0, $a2
/* 1361FC 80242EBC 44820000 */  mtc1      $v0, $f0
/* 136200 80242EC0 00000000 */  nop       
/* 136204 80242EC4 46800021 */  cvt.d.w   $f0, $f0
/* 136208 80242EC8 46240002 */  mul.d     $f0, $f0, $f4
/* 13620C 80242ECC 00000000 */  nop       
/* 136210 80242ED0 4620118D */  trunc.w.d $f6, $f2
/* 136214 80242ED4 44073000 */  mfc1      $a3, $f6
/* 136218 80242ED8 4620018D */  trunc.w.d $f6, $f0
/* 13621C 80242EDC 44083000 */  mfc1      $t0, $f6
/* 136220 80242EE0 14A30003 */  bne       $a1, $v1, .L80242EF0
/* 136224 80242EE4 00000000 */   nop      
/* 136228 80242EE8 10860007 */  beq       $a0, $a2, .L80242F08
/* 13622C 80242EEC 00000000 */   nop      
.L80242EF0:
/* 136230 80242EF0 14E00005 */  bnez      $a3, .L80242F08
/* 136234 80242EF4 00000000 */   nop      
/* 136238 80242EF8 15000003 */  bnez      $t0, .L80242F08
/* 13623C 80242EFC 00000000 */   nop      
/* 136240 80242F00 AD450000 */  sw        $a1, ($t2)
/* 136244 80242F04 AD240000 */  sw        $a0, ($t1)
.L80242F08:
/* 136248 80242F08 3C038025 */  lui       $v1, %hi(gPauseMenuCursorPos)
/* 13624C 80242F0C 2463EF9C */  addiu     $v1, $v1, %lo(gPauseMenuCursorPos)
/* 136250 80242F10 8C620000 */  lw        $v0, ($v1)
/* 136254 80242F14 00471021 */  addu      $v0, $v0, $a3
/* 136258 80242F18 AC620000 */  sw        $v0, ($v1)
/* 13625C 80242F1C 3C038025 */  lui       $v1, 0x8025
/* 136260 80242F20 2463EFA0 */  addiu     $v1, $v1, -0x1060
/* 136264 80242F24 8C620000 */  lw        $v0, ($v1)
/* 136268 80242F28 3C048025 */  lui       $a0, %hi(gPauseMenuCursorTargetOpacity)
/* 13626C 80242F2C 8C84EFB0 */  lw        $a0, %lo(gPauseMenuCursorTargetOpacity)($a0)
/* 136270 80242F30 00481021 */  addu      $v0, $v0, $t0
/* 136274 80242F34 14800009 */  bnez      $a0, .L80242F5C
/* 136278 80242F38 AC620000 */   sw       $v0, ($v1)
/* 13627C 80242F3C 3C038025 */  lui       $v1, %hi(gPauseMenuCursorOpacity)
/* 136280 80242F40 2463EFA4 */  addiu     $v1, $v1, %lo(gPauseMenuCursorOpacity)
/* 136284 80242F44 8C620000 */  lw        $v0, ($v1)
/* 136288 80242F48 2442FF80 */  addiu     $v0, $v0, -0x80
/* 13628C 80242F4C 0441000C */  bgez      $v0, .L80242F80
/* 136290 80242F50 AC620000 */   sw       $v0, ($v1)
/* 136294 80242F54 08090BE0 */  j         .L80242F80
/* 136298 80242F58 AC600000 */   sw       $zero, ($v1)
.L80242F5C:
/* 13629C 80242F5C 3C038025 */  lui       $v1, %hi(gPauseMenuCursorOpacity)
/* 1362A0 80242F60 2463EFA4 */  addiu     $v1, $v1, %lo(gPauseMenuCursorOpacity)
/* 1362A4 80242F64 8C620000 */  lw        $v0, ($v1)
/* 1362A8 80242F68 24420020 */  addiu     $v0, $v0, 0x20
/* 1362AC 80242F6C AC620000 */  sw        $v0, ($v1)
/* 1362B0 80242F70 28420100 */  slti      $v0, $v0, 0x100
/* 1362B4 80242F74 14400003 */  bnez      $v0, .L80242F84
/* 1362B8 80242F78 240200FF */   addiu    $v0, $zero, 0xff
/* 1362BC 80242F7C AC620000 */  sw        $v0, ($v1)
.L80242F80:
/* 1362C0 80242F80 240200FF */  addiu     $v0, $zero, 0xff
.L80242F84:
/* 1362C4 80242F84 3C018025 */  lui       $at, %hi(gPauseMenuCursorTargetOpacity)
/* 1362C8 80242F88 03E00008 */  jr        $ra
/* 1362CC 80242F8C AC22EFB0 */   sw       $v0, %lo(gPauseMenuCursorTargetOpacity)($at)
