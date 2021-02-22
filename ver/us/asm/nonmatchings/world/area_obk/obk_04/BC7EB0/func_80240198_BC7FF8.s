.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240198_BC7FF8
/* BC7FF8 80240198 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC7FFC 8024019C AFBF0010 */  sw        $ra, 0x10($sp)
/* BC8000 802401A0 0C00EABB */  jal       get_npc_unsafe
/* BC8004 802401A4 24040001 */   addiu    $a0, $zero, 1
/* BC8008 802401A8 0C090034 */  jal       func_802400D0_BC7F30
/* BC800C 802401AC 0040202D */   daddu    $a0, $v0, $zero
/* BC8010 802401B0 0C00EABB */  jal       get_npc_unsafe
/* BC8014 802401B4 24040002 */   addiu    $a0, $zero, 2
/* BC8018 802401B8 0C090034 */  jal       func_802400D0_BC7F30
/* BC801C 802401BC 0040202D */   daddu    $a0, $v0, $zero
/* BC8020 802401C0 0C00EABB */  jal       get_npc_unsafe
/* BC8024 802401C4 24040003 */   addiu    $a0, $zero, 3
/* BC8028 802401C8 0C090034 */  jal       func_802400D0_BC7F30
/* BC802C 802401CC 0040202D */   daddu    $a0, $v0, $zero
/* BC8030 802401D0 0C00EABB */  jal       get_npc_unsafe
/* BC8034 802401D4 24040004 */   addiu    $a0, $zero, 4
/* BC8038 802401D8 0C090034 */  jal       func_802400D0_BC7F30
/* BC803C 802401DC 0040202D */   daddu    $a0, $v0, $zero
/* BC8040 802401E0 0C00EABB */  jal       get_npc_unsafe
/* BC8044 802401E4 24040005 */   addiu    $a0, $zero, 5
/* BC8048 802401E8 0C090034 */  jal       func_802400D0_BC7F30
/* BC804C 802401EC 0040202D */   daddu    $a0, $v0, $zero
/* BC8050 802401F0 0C00EABB */  jal       get_npc_unsafe
/* BC8054 802401F4 24040006 */   addiu    $a0, $zero, 6
/* BC8058 802401F8 0C090034 */  jal       func_802400D0_BC7F30
/* BC805C 802401FC 0040202D */   daddu    $a0, $v0, $zero
/* BC8060 80240200 0C00EABB */  jal       get_npc_unsafe
/* BC8064 80240204 24040007 */   addiu    $a0, $zero, 7
/* BC8068 80240208 0C090034 */  jal       func_802400D0_BC7F30
/* BC806C 8024020C 0040202D */   daddu    $a0, $v0, $zero
/* BC8070 80240210 0C00EABB */  jal       get_npc_unsafe
/* BC8074 80240214 24040008 */   addiu    $a0, $zero, 8
/* BC8078 80240218 0C090034 */  jal       func_802400D0_BC7F30
/* BC807C 8024021C 0040202D */   daddu    $a0, $v0, $zero
/* BC8080 80240220 8FBF0010 */  lw        $ra, 0x10($sp)
/* BC8084 80240224 03E00008 */  jr        $ra
/* BC8088 80240228 27BD0018 */   addiu    $sp, $sp, 0x18
