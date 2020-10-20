.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_D95640
/* D95640 80240050 3C02FEFF */  lui       $v0, 0xfeff
/* D95644 80240054 3442FFFF */  ori       $v0, $v0, 0xffff
/* D95648 80240058 00822024 */  and       $a0, $a0, $v0
/* D9564C 8024005C 3C02FFF9 */  lui       $v0, 0xfff9
/* D95650 80240060 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D95654 80240064 00821821 */  addu      $v1, $a0, $v0
/* D95658 80240068 2C620010 */  sltiu     $v0, $v1, 0x10
/* D9565C 8024006C 10400003 */  beqz      $v0, .L8024007C
/* D95660 80240070 30620001 */   andi     $v0, $v1, 1
/* D95664 80240074 54400001 */  bnel      $v0, $zero, .L8024007C
/* D95668 80240078 2484FFFF */   addiu    $a0, $a0, -1
.L8024007C:
/* D9566C 8024007C 03E00008 */  jr        $ra
/* D95670 80240080 0080102D */   daddu    $v0, $a0, $zero
