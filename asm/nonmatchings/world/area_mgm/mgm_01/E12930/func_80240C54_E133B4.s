.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C54_E133B4
/* E133B4 80240C54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E133B8 80240C58 AFBF0010 */  sw        $ra, 0x10($sp)
/* E133BC 80240C5C 0C00FB3A */  jal       get_enemy
/* E133C0 80240C60 0000202D */   daddu    $a0, $zero, $zero
/* E133C4 80240C64 3C060001 */  lui       $a2, 1
/* E133C8 80240C68 3C058011 */  lui       $a1, %hi(gPlayerData)
/* E133CC 80240C6C 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* E133D0 80240C70 34C6869F */  ori       $a2, $a2, 0x869f
/* E133D4 80240C74 8C440080 */  lw        $a0, 0x80($v0)
/* E133D8 80240C78 8CA20330 */  lw        $v0, 0x330($a1)
/* E133DC 80240C7C 8C83000C */  lw        $v1, 0xc($a0)
/* E133E0 80240C80 00431021 */  addu      $v0, $v0, $v1
/* E133E4 80240C84 ACA20330 */  sw        $v0, 0x330($a1)
/* E133E8 80240C88 00C2102B */  sltu      $v0, $a2, $v0
/* E133EC 80240C8C 10400002 */  beqz      $v0, .L80240C98
/* E133F0 80240C90 00A0382D */   daddu    $a3, $a1, $zero
/* E133F4 80240C94 ACA60330 */  sw        $a2, 0x330($a1)
.L80240C98:
/* E133F8 80240C98 94E20334 */  lhu       $v0, 0x334($a3)
/* E133FC 80240C9C 8C83000C */  lw        $v1, 0xc($a0)
/* E13400 80240CA0 0043102A */  slt       $v0, $v0, $v1
/* E13404 80240CA4 10400003 */  beqz      $v0, .L80240CB4
/* E13408 80240CA8 00000000 */   nop
/* E1340C 80240CAC 9482000E */  lhu       $v0, 0xe($a0)
/* E13410 80240CB0 A4E20334 */  sh        $v0, 0x334($a3)
.L80240CB4:
/* E13414 80240CB4 8C84000C */  lw        $a0, 0xc($a0)
/* E13418 80240CB8 0C0496FA */  jal       set_message_value
/* E1341C 80240CBC 0000282D */   daddu    $a1, $zero, $zero
/* E13420 80240CC0 8FBF0010 */  lw        $ra, 0x10($sp)
/* E13424 80240CC4 24020002 */  addiu     $v0, $zero, 2
/* E13428 80240CC8 03E00008 */  jr        $ra
/* E1342C 80240CCC 27BD0018 */   addiu    $sp, $sp, 0x18
