.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057CB4
/* 330B4 80057CB4 000528C3 */  sra       $a1, $a1, 3
/* 330B8 80057CB8 50A0000E */  beql      $a1, $zero, .L80057CF4
/* 330BC 80057CBC 00041400 */   sll      $v0, $a0, 0x10
/* 330C0 80057CC0 30E2FFFF */  andi      $v0, $a3, 0xffff
/* 330C4 80057CC4 00450018 */  mult      $v0, $a1
/* 330C8 80057CC8 00001012 */  mflo      $v0
/* 330CC 80057CCC 00061C00 */  sll       $v1, $a2, 0x10
/* 330D0 80057CD0 00031C03 */  sra       $v1, $v1, 0x10
/* 330D4 80057CD4 00650018 */  mult      $v1, $a1
/* 330D8 80057CD8 00021403 */  sra       $v0, $v0, 0x10
/* 330DC 80057CDC 00001812 */  mflo      $v1
/* 330E0 80057CE0 00431021 */  addu      $v0, $v0, $v1
/* 330E4 80057CE4 00821021 */  addu      $v0, $a0, $v0
/* 330E8 80057CE8 00021400 */  sll       $v0, $v0, 0x10
/* 330EC 80057CEC 03E00008 */  jr        $ra
/* 330F0 80057CF0 00021403 */   sra      $v0, $v0, 0x10
.L80057CF4:
/* 330F4 80057CF4 03E00008 */  jr        $ra
/* 330F8 80057CF8 00021403 */   sra      $v0, $v0, 0x10
/* 330FC 80057CFC 00000000 */  nop
