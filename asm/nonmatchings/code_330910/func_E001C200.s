.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E001C200
/* 330B10 E001C200 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 330B14 E001C204 0080282D */  daddu     $a1, $a0, $zero
/* 330B18 E001C208 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 330B1C E001C20C 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 330B20 E001C210 AFBF0020 */  sw        $ra, 0x20($sp)
/* 330B24 E001C214 8CA2000C */  lw        $v0, 0xc($a1)
/* 330B28 E001C218 C4640028 */  lwc1      $f4, 0x28($v1)
/* 330B2C E001C21C C4420000 */  lwc1      $f2, ($v0)
/* 330B30 E001C220 46041001 */  sub.s     $f0, $f2, $f4
/* 330B34 E001C224 3C014348 */  lui       $at, 0x4348
/* 330B38 E001C228 44813000 */  mtc1      $at, $f6
/* 330B3C E001C22C 00000000 */  nop       
/* 330B40 E001C230 4600303C */  c.lt.s    $f6, $f0
/* 330B44 E001C234 00000000 */  nop       
/* 330B48 E001C238 45000005 */  bc1f      .LE001C250
/* 330B4C E001C23C 27A40010 */   addiu    $a0, $sp, 0x10
/* 330B50 E001C240 3C0143C8 */  lui       $at, 0x43c8
/* 330B54 E001C244 44810000 */  mtc1      $at, $f0
/* 330B58 E001C248 0800709D */  j         .LE001C274
/* 330B5C E001C24C 46001001 */   sub.s    $f0, $f2, $f0
.LE001C250:
/* 330B60 E001C250 46022001 */  sub.s     $f0, $f4, $f2
/* 330B64 E001C254 4600303C */  c.lt.s    $f6, $f0
/* 330B68 E001C258 00000000 */  nop       
/* 330B6C E001C25C 45000006 */  bc1f      .LE001C278
/* 330B70 E001C260 00000000 */   nop      
/* 330B74 E001C264 3C0143C8 */  lui       $at, 0x43c8
/* 330B78 E001C268 44810000 */  mtc1      $at, $f0
/* 330B7C E001C26C 00000000 */  nop       
/* 330B80 E001C270 46001000 */  add.s     $f0, $f2, $f0
.LE001C274:
/* 330B84 E001C274 E4400000 */  swc1      $f0, ($v0)
.LE001C278:
/* 330B88 E001C278 C4420008 */  lwc1      $f2, 8($v0)
/* 330B8C E001C27C C4640030 */  lwc1      $f4, 0x30($v1)
/* 330B90 E001C280 46041001 */  sub.s     $f0, $f2, $f4
/* 330B94 E001C284 3C014348 */  lui       $at, 0x4348
/* 330B98 E001C288 44813000 */  mtc1      $at, $f6
/* 330B9C E001C28C 00000000 */  nop       
/* 330BA0 E001C290 4600303C */  c.lt.s    $f6, $f0
/* 330BA4 E001C294 00000000 */  nop       
/* 330BA8 E001C298 45020005 */  bc1fl     .LE001C2B0
/* 330BAC E001C29C 46022001 */   sub.s    $f0, $f4, $f2
/* 330BB0 E001C2A0 3C0143C8 */  lui       $at, 0x43c8
/* 330BB4 E001C2A4 44810000 */  mtc1      $at, $f0
/* 330BB8 E001C2A8 080070B4 */  j         .LE001C2D0
/* 330BBC E001C2AC 46001001 */   sub.s    $f0, $f2, $f0
.LE001C2B0:
/* 330BC0 E001C2B0 4600303C */  c.lt.s    $f6, $f0
/* 330BC4 E001C2B4 00000000 */  nop       
/* 330BC8 E001C2B8 45000006 */  bc1f      .LE001C2D4
/* 330BCC E001C2BC 00000000 */   nop      
/* 330BD0 E001C2C0 3C0143C8 */  lui       $at, 0x43c8
/* 330BD4 E001C2C4 44810000 */  mtc1      $at, $f0
/* 330BD8 E001C2C8 00000000 */  nop       
/* 330BDC E001C2CC 46001000 */  add.s     $f0, $f2, $f0
.LE001C2D0:
/* 330BE0 E001C2D0 E4400008 */  swc1      $f0, 8($v0)
.LE001C2D4:
/* 330BE4 E001C2D4 3C02E002 */  lui       $v0, %hi(D_E001C30C)
/* 330BE8 E001C2D8 2442C30C */  addiu     $v0, $v0, %lo(D_E001C30C)
/* 330BEC E001C2DC AC82000C */  sw        $v0, 0xc($a0)
/* 330BF0 E001C2E0 2402002D */  addiu     $v0, $zero, 0x2d
/* 330BF4 E001C2E4 AC850008 */  sw        $a1, 8($a0)
/* 330BF8 E001C2E8 AC800004 */  sw        $zero, 4($a0)
/* 330BFC E001C2EC 0C080120 */  jal       func_E0200480
/* 330C00 E001C2F0 AC820000 */   sw       $v0, ($a0)
/* 330C04 E001C2F4 8C430000 */  lw        $v1, ($v0)
/* 330C08 E001C2F8 34630002 */  ori       $v1, $v1, 2
/* 330C0C E001C2FC AC430000 */  sw        $v1, ($v0)
/* 330C10 E001C300 8FBF0020 */  lw        $ra, 0x20($sp)
/* 330C14 E001C304 03E00008 */  jr        $ra
/* 330C18 E001C308 27BD0028 */   addiu    $sp, $sp, 0x28
