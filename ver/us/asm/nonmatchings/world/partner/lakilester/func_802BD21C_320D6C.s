.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD21C_320D6C
/* 320D6C 802BD21C C4800038 */  lwc1      $f0, 0x38($a0)
/* 320D70 802BD220 C482003C */  lwc1      $f2, 0x3c($a0)
/* 320D74 802BD224 C4840040 */  lwc1      $f4, 0x40($a0)
/* 320D78 802BD228 24020026 */  addiu     $v0, $zero, 0x26
/* 320D7C 802BD22C A48200A8 */  sh        $v0, 0xa8($a0)
/* 320D80 802BD230 24020024 */  addiu     $v0, $zero, 0x24
/* 320D84 802BD234 A48200A6 */  sh        $v0, 0xa6($a0)
/* 320D88 802BD238 3C020001 */  lui       $v0, 1
/* 320D8C 802BD23C AC820080 */  sw        $v0, 0x80($a0)
/* 320D90 802BD240 24020001 */  addiu     $v0, $zero, 1
/* 320D94 802BD244 3C01802C */  lui       $at, %hi(D_802BFF18)
/* 320D98 802BD248 AC20FF18 */  sw        $zero, %lo(D_802BFF18)($at)
/* 320D9C 802BD24C 3C01802C */  lui       $at, %hi(D_802BFF04)
/* 320DA0 802BD250 AC20FF04 */  sw        $zero, %lo(D_802BFF04)($at)
/* 320DA4 802BD254 3C01802C */  lui       $at, %hi(D_802BFF08)
/* 320DA8 802BD258 AC20FF08 */  sw        $zero, %lo(D_802BFF08)($at)
/* 320DAC 802BD25C 3C01802C */  lui       $at, %hi(D_802BFF0C)
/* 320DB0 802BD260 AC20FF0C */  sw        $zero, %lo(D_802BFF0C)($at)
/* 320DB4 802BD264 3C01802C */  lui       $at, %hi(D_802BFF10)
/* 320DB8 802BD268 AC22FF10 */  sw        $v0, %lo(D_802BFF10)($at)
/* 320DBC 802BD26C 3C01802C */  lui       $at, %hi(D_802BFF1C)
/* 320DC0 802BD270 AC20FF1C */  sw        $zero, %lo(D_802BFF1C)($at)
/* 320DC4 802BD274 3C01802C */  lui       $at, %hi(D_802BFF20)
/* 320DC8 802BD278 AC20FF20 */  sw        $zero, %lo(D_802BFF20)($at)
/* 320DCC 802BD27C 3C01802C */  lui       $at, %hi(D_802BFF24)
/* 320DD0 802BD280 AC20FF24 */  sw        $zero, %lo(D_802BFF24)($at)
/* 320DD4 802BD284 3C01802C */  lui       $at, %hi(D_802BFF28)
/* 320DD8 802BD288 AC20FF28 */  sw        $zero, %lo(D_802BFF28)($at)
/* 320DDC 802BD28C E4800060 */  swc1      $f0, 0x60($a0)
/* 320DE0 802BD290 E4820064 */  swc1      $f2, 0x64($a0)
/* 320DE4 802BD294 03E00008 */  jr        $ra
/* 320DE8 802BD298 E4840068 */   swc1     $f4, 0x68($a0)
