.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_D62D60
/* D62D60 80240050 3C02FEFF */  lui       $v0, 0xfeff
/* D62D64 80240054 3442FFFF */  ori       $v0, $v0, 0xffff
/* D62D68 80240058 00822024 */  and       $a0, $a0, $v0
/* D62D6C 8024005C 3C02FFF9 */  lui       $v0, 0xfff9
/* D62D70 80240060 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D62D74 80240064 00821821 */  addu      $v1, $a0, $v0
/* D62D78 80240068 2C620010 */  sltiu     $v0, $v1, 0x10
/* D62D7C 8024006C 10400003 */  beqz      $v0, .L8024007C
/* D62D80 80240070 30620001 */   andi     $v0, $v1, 1
/* D62D84 80240074 54400001 */  bnel      $v0, $zero, .L8024007C
/* D62D88 80240078 2484FFFF */   addiu    $a0, $a0, -1
.L8024007C:
/* D62D8C 8024007C 03E00008 */  jr        $ra
/* D62D90 80240080 0080102D */   daddu    $v0, $a0, $zero
