.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel DispatchDamagePlayerEvent
/* 1A31FC 8027491C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1A3200 80274920 AFB10014 */  sw    $s1, 0x14($sp)
/* 1A3204 80274924 0080882D */  daddu $s1, $a0, $zero
/* 1A3208 80274928 AFBF0018 */  sw    $ra, 0x18($sp)
/* 1A320C 8027492C AFB00010 */  sw    $s0, 0x10($sp)
/* 1A3210 80274930 8E30000C */  lw    $s0, 0xc($s1)
/* 1A3214 80274934 8E050000 */  lw    $a1, ($s0)
/* 1A3218 80274938 0C0B1EAF */  jal   get_variable
/* 1A321C 8027493C 26100004 */   addiu $s0, $s0, 4
/* 1A3220 80274940 8E050000 */  lw    $a1, ($s0)
/* 1A3224 80274944 0C09CCDF */  jal   dispatch_damage_event_player_0
/* 1A3228 80274948 0040202D */   daddu $a0, $v0, $zero
/* 1A322C 8027494C 04420005 */  bltzl $v0, .L80274964
/* 1A3230 80274950 0000102D */   daddu $v0, $zero, $zero
/* 1A3234 80274954 0C0B1069 */  jal   does_script_exist_by_ref
/* 1A3238 80274958 0220202D */   daddu $a0, $s1, $zero
/* 1A323C 8027495C 0002102B */  sltu  $v0, $zero, $v0
/* 1A3240 80274960 00021040 */  sll   $v0, $v0, 1
.L80274964:
/* 1A3244 80274964 8FBF0018 */  lw    $ra, 0x18($sp)
/* 1A3248 80274968 8FB10014 */  lw    $s1, 0x14($sp)
/* 1A324C 8027496C 8FB00010 */  lw    $s0, 0x10($sp)
/* 1A3250 80274970 03E00008 */  jr    $ra
/* 1A3254 80274974 27BD0020 */   addiu $sp, $sp, 0x20

