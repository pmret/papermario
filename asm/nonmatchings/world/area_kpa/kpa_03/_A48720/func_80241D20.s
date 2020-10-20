.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D20
/* A4A2E0 80241D20 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A4A2E4 80241D24 AFBF0020 */  sw        $ra, 0x20($sp)
/* A4A2E8 80241D28 8C820148 */  lw        $v0, 0x148($a0)
/* A4A2EC 80241D2C 0C00EABB */  jal       get_npc_unsafe
/* A4A2F0 80241D30 84440008 */   lh       $a0, 8($v0)
/* A4A2F4 80241D34 240300FF */  addiu     $v1, $zero, 0xff
/* A4A2F8 80241D38 0000282D */  daddu     $a1, $zero, $zero
/* A4A2FC 80241D3C 00A0302D */  daddu     $a2, $a1, $zero
/* A4A300 80241D40 A04300AC */  sb        $v1, 0xac($v0)
/* A4A304 80241D44 AFA00010 */  sw        $zero, 0x10($sp)
/* A4A308 80241D48 AFA00014 */  sw        $zero, 0x14($sp)
/* A4A30C 80241D4C AFA00018 */  sw        $zero, 0x18($sp)
/* A4A310 80241D50 8C440024 */  lw        $a0, 0x24($v0)
/* A4A314 80241D54 0C0B7A25 */  jal       func_802DE894
/* A4A318 80241D58 00A0382D */   daddu    $a3, $a1, $zero
/* A4A31C 80241D5C 8FBF0020 */  lw        $ra, 0x20($sp)
/* A4A320 80241D60 24020002 */  addiu     $v0, $zero, 2
/* A4A324 80241D64 03E00008 */  jr        $ra
/* A4A328 80241D68 27BD0028 */   addiu    $sp, $sp, 0x28
