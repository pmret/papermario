.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_01_Quizmo_UnkE
/* 803200 80242980 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 803204 80242984 AFBF0010 */  sw        $ra, 0x10($sp)
/* 803208 80242988 8C82000C */  lw        $v0, 0xc($a0)
/* 80320C 8024298C 0C0B1EAF */  jal       evt_get_variable
/* 803210 80242990 8C450000 */   lw       $a1, ($v0)
/* 803214 80242994 0040202D */  daddu     $a0, $v0, $zero
/* 803218 80242998 3C028026 */  lui       $v0, %hi(mac_01_Quizmo_StageEffect)
/* 80321C 8024299C 8C422A60 */  lw        $v0, %lo(mac_01_Quizmo_StageEffect)($v0)
/* 803220 802429A0 24030001 */  addiu     $v1, $zero, 1
/* 803224 802429A4 8C45000C */  lw        $a1, 0xc($v0)
/* 803228 802429A8 1083000D */  beq       $a0, $v1, .L802429E0
/* 80322C 802429AC 28820002 */   slti     $v0, $a0, 2
/* 803230 802429B0 10400005 */  beqz      $v0, .L802429C8
/* 803234 802429B4 24020002 */   addiu    $v0, $zero, 2
/* 803238 802429B8 10800007 */  beqz      $a0, .L802429D8
/* 80323C 802429BC 240200C0 */   addiu    $v0, $zero, 0xc0
/* 803240 802429C0 08090A7C */  j         .L802429F0
/* 803244 802429C4 ACA00038 */   sw       $zero, 0x38($a1)
.L802429C8:
/* 803248 802429C8 10820008 */  beq       $a0, $v0, .L802429EC
/* 80324C 802429CC 24020040 */   addiu    $v0, $zero, 0x40
/* 803250 802429D0 08090A7C */  j         .L802429F0
/* 803254 802429D4 ACA00038 */   sw       $zero, 0x38($a1)
.L802429D8:
/* 803258 802429D8 08090A7C */  j         .L802429F0
/* 80325C 802429DC ACA20038 */   sw       $v0, 0x38($a1)
.L802429E0:
/* 803260 802429E0 24020080 */  addiu     $v0, $zero, 0x80
/* 803264 802429E4 08090A7C */  j         .L802429F0
/* 803268 802429E8 ACA20038 */   sw       $v0, 0x38($a1)
.L802429EC:
/* 80326C 802429EC ACA20038 */  sw        $v0, 0x38($a1)
.L802429F0:
/* 803270 802429F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 803274 802429F4 24020002 */  addiu     $v0, $zero, 2
/* 803278 802429F8 03E00008 */  jr        $ra
/* 80327C 802429FC 27BD0018 */   addiu    $sp, $sp, 0x18
